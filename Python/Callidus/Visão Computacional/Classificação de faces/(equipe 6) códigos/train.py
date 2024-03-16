import os
import matplotlib.pyplot as plt
import tensorflow as tf
os.environ['KMP_DUPLICATE_LIB_OK'] = 'True'


class Train():

    # Checks if there is a gpu available

    if tf.test.is_gpu_available():
        print("GPU is available")
    else:
        print("GPU is not available")

    train_dir = os.path.join(
        'D:\\Usuários\\mateus\\OneDrive - seducam.g12.br\\Documentos\\Programas\\Python\\Callidus\\Visão Computacional\\Classificação de faces\\training_datasets',
        'D:\\Usuários\\mateus\\OneDrive - seducam.g12.br\\Documentos\\Programas\\Python\\Callidus\\Visão Computacional\\Classificação de faces\\training_datasets\\train')
    validation_dir = os.path.join(
        'D:\\Usuários\\mateus\\OneDrive - seducam.g12.br\\Documentos\\Programas\\Python\\Callidus\\Visão Computacional\\Classificação de faces\\training_datasets',
        'D:\\Usuários\\mateus\\OneDrive - seducam.g12.br\\Documentos\\Programas\\Python\\Callidus\\Visão Computacional\\Classificação de faces\\training_datasets\\validation')

    BATCH_SIZE = 2
    IMG_SIZE = (120, 160)

    train_dataset = tf.keras.utils.image_dataset_from_directory(train_dir,
                                                                shuffle=True,
                                                                batch_size=BATCH_SIZE,
                                                                image_size=IMG_SIZE)

    validation_dataset = tf.keras.utils.image_dataset_from_directory(validation_dir,
                                                                     shuffle=True,
                                                                     batch_size=BATCH_SIZE,
                                                                     image_size=IMG_SIZE)

    class_names = train_dataset.class_names

    print(class_names)

    val_batches = tf.data.experimental.cardinality(validation_dataset)
    test_dataset = validation_dataset.take(val_batches // 5)
    validation_dataset = validation_dataset.skip(val_batches // 5)

    print('Number of validation batches: %d' % tf.data.experimental.cardinality(validation_dataset))
    print('Number of test batches: %d' % tf.data.experimental.cardinality(test_dataset))

    AUTOTUNE = tf.data.AUTOTUNE

    train_dataset = train_dataset.prefetch(buffer_size=AUTOTUNE)
    validation_dataset = validation_dataset.prefetch(buffer_size=AUTOTUNE)
    test_dataset = test_dataset.prefetch(buffer_size=AUTOTUNE)

    data_augmentation = tf.keras.Sequential([
      tf.keras.layers.RandomFlip('horizontal'),
      tf.keras.layers.RandomRotation(0.2),
    ])

    for image, _ in train_dataset.take(1):
        plt.figure(figsize=(10, 10))
        first_image = image[0]
        for i in range(9):
            ax = plt.subplot(3, 3, i + 1)
            augmented_image = data_augmentation(tf.expand_dims(first_image, 0))
            plt.imshow(augmented_image[0] / 255)
            plt.axis('off')

    preprocess_input = tf.keras.layers.Rescaling(1./127.5, offset=-1)

    # Create the base model from the pre-trained model MobileNet V2
    IMG_SHAPE = IMG_SIZE + (3,)
    base_model = tf.keras.applications.VGG16(input_shape=IMG_SHAPE,
                                                   include_top=False,
                                                   weights='imagenet')

    image_batch, label_batch = next(iter(train_dataset))
    feature_batch = base_model(image_batch)
    print(feature_batch.shape)

    base_model.trainable = False

    # Let's take a look at the base model architecture
    base_model.summary()

    global_average_layer = tf.keras.layers.GlobalAveragePooling2D()
    feature_batch_average = global_average_layer(feature_batch)
    print(feature_batch_average.shape)

    prediction_layer = tf.keras.layers.Dense(len(class_names), activation='softmax')
    nonlinear_layer = tf.keras.layers.Dense(2*len(class_names), activation='relu')
    prediction_batch = prediction_layer(nonlinear_layer(feature_batch_average))
    print(prediction_batch.shape)

    inputs = tf.keras.Input(shape=(120, 160, 3))
    x = data_augmentation(inputs)
    x = preprocess_input(x)
    x = base_model(x, training=False)
    x = global_average_layer(x)
    x = tf.keras.layers.Dropout(0.2)(x)
    x = nonlinear_layer(x)
    outputs = prediction_layer(x)
    model = tf.keras.Model(inputs, outputs)

    base_learning_rate = 0.0001


    model.compile(optimizer=tf.keras.optimizers.Adam(learning_rate=base_learning_rate),
                  loss=tf.keras.losses.sparse_categorical_crossentropy,
                  metrics=['accuracy'])

    model.summary

    len(model.trainable_variables)

    initial_epochs = 10

    loss0, accuracy0 = model.evaluate(validation_dataset)

    print("initial loss: {:.2f}".format(loss0))
    print("initial accuracy: {:.2f}".format(accuracy0))

    with tf.device('/device:GPU:1'):

        history = model.fit(train_dataset,
                            epochs=initial_epochs,
                            validation_data=validation_dataset)

    acc = history.history['accuracy']
    val_acc = history.history['val_accuracy']

    loss = history.history['loss']
    val_loss = history.history['val_loss']

    plt.figure(figsize=(8, 8))
    plt.subplot(2, 1, 1)
    plt.plot(acc, label='Training Accuracy')
    plt.plot(val_acc, label='Validation Accuracy')
    plt.legend(loc='lower right')
    plt.ylabel('Accuracy')
    plt.ylim([min(plt.ylim()),1])
    plt.title('Training and Validation Accuracy')

    plt.subplot(2, 1, 2)
    plt.plot(loss, label='Training Loss')
    plt.plot(val_loss, label='Validation Loss')
    plt.legend(loc='upper right')
    plt.ylabel('Cross Entropy')
    plt.ylim([0,1.0])
    plt.title('Training and Validation Loss')
    plt.xlabel('epoch')
    plt.show()

    base_model.trainable = True


    # Let's take a look to see how many layers are in the base model
    print("Number of layers in the base model: ", len(base_model.layers))

    # Fine-tune from this layer onwards
    fine_tune_at = 100

    # Freeze all the layers before the `fine_tune_at` layer
    for layer in base_model.layers[:fine_tune_at]:
      layer.trainable = False


    model.compile(loss=tf.keras.losses.sparse_categorical_crossentropy,
                  optimizer = tf.keras.optimizers.RMSprop(learning_rate=base_learning_rate/10),
                  metrics=['accuracy'])

    model.summary()

    len(model.trainable_variables)

    fine_tune_epochs = 10
    total_epochs =  initial_epochs + fine_tune_epochs

    with tf.device('/device:GPU:1'):

        history_fine = model.fit(train_dataset,
                                 epochs=total_epochs,
                                 initial_epoch=history.epoch[-1],
                                 validation_data=validation_dataset)

    acc += history_fine.history['accuracy']
    val_acc += history_fine.history['val_accuracy']

    loss += history_fine.history['loss']
    val_loss += history_fine.history['val_loss']

    plt.figure(figsize=(8, 8))
    plt.subplot(2, 1, 1)
    plt.plot(acc, label='Training Accuracy')
    plt.plot(val_acc, label='Validation Accuracy')
    plt.ylim([0.8, 1])
    plt.plot([initial_epochs-1,initial_epochs-1],
              plt.ylim(), label='Start Fine Tuning')
    plt.legend(loc='lower right')
    plt.title('Training and Validation Accuracy')

    plt.subplot(2, 1, 2)
    plt.plot(loss, label='Training Loss')
    plt.plot(val_loss, label='Validation Loss')
    plt.ylim([0, 1.0])
    plt.plot([initial_epochs-1,initial_epochs-1],
             plt.ylim(), label='Start Fine Tuning')
    plt.legend(loc='upper right')
    plt.title('Training and Validation Loss')
    plt.xlabel('epoch')
    plt.show()

    loss, accuracy = model.evaluate(test_dataset)
    print('Test accuracy :', accuracy)

    import numpy as np
    # Retrieve a batch of images from the test set
    image_batch, label_batch = test_dataset.as_numpy_iterator().next()


    predictions = model.predict_on_batch(image_batch)
    predictions = np.argmax(predictions,axis=-1)

    print('Predictions:\n', predictions)
    print('Labels:\n', label_batch)

    plt.figure(figsize=(10, 10))
    for i in range(2):
      ax = plt.subplot(3, 3, i + 1)
      plt.imshow(image_batch[i].astype("uint8"))
      plt.title(class_names[predictions[i]])
      plt.axis("off")


    # serialize model to JSON
    model_json = model.to_json()
    with open("model.json", "w") as json_file:
        json_file.write(model_json)
    # serialize weights to HDF5
    model.save_weights("model.h5")
    print("Saved model to disk")
