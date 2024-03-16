import os
import tensorflow as tf
import face_recognition
import cv2
import numpy

os.environ['KMP_DUPLICATE_LIB_OK'] = 'True'

train_dir = os.path.join(
        'D:\\Usuários\\mateus\\OneDrive - seducam.g12.br\\Documentos\\Programas\\Python\\Callidus\\Visão Computacional\\Classificação de faces\\training_datasets',
        'D:\\Usuários\\mateus\\OneDrive - seducam.g12.br\\Documentos\\Programas\\Python\\Callidus\\Visão Computacional\\Classificação de faces\\training_datasets\\train')

BATCH_SIZE = 2
IMG_SIZE = (120, 160)

train_dataset = tf.keras.utils.image_dataset_from_directory(train_dir,
                                                            shuffle=True,
                                                            batch_size=BATCH_SIZE,
                                                            image_size=IMG_SIZE)

class_names = train_dataset.class_names

from keras.models import model_from_json

# load json and create model
json_file = open('model.json', 'r')
loaded_model_json = json_file.read()
json_file.close()
loaded_model = model_from_json(loaded_model_json)
# load weights into new model
loaded_model.load_weights("model.h5")
print("Loaded model from disk")
model = loaded_model

# Get a reference to webcam #0 (the default one)
video_capture = cv2.VideoCapture(0)


class Webcam():
    def pred_frame(frame):
        pred = model.predict(frame)
        return pred[0]

    while True:
        ret, frame = video_capture.read()

        rgb_frame = frame[:, :, ::-1]

        face_locations = face_recognition.face_locations(rgb_frame)
        face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)

        for (top, right, bottom, left), face_encoding in zip(face_locations, face_encodings):

            name = "Não Identificado"

            frame_pred = cv2.resize(frame, (120, 160))
            frame_pred = frame_pred.reshape(1, 120, 160, 3)
            pred = pred_frame(frame_pred)
            pred = numpy.argmax(pred, axis=-1)

            if class_names[pred] == 'mm':
                name = 'Matheus Martins'
                print("Você é Matheus Martins.")

            elif class_names[pred] == 'mb':
                name = 'Mateus Bastos'
                print("Você é Mateus Bastos.")

            elif class_names[pred] == 'vh':
                name = 'Vitor Hugo'
                print("Você é Vitor Hugo.")

            elif class_names[pred] == 'ja':
                name = 'Josué Azevedo'
                print("Você é Josué Azevedo.")

            elif class_names[pred] == 'rc':
                name = 'Renan Cena'
                print("Você é Renan Cena.")

            cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255), 2)

            cv2.rectangle(frame, (left, bottom - 30), (right, bottom), (0, 0, 255), cv2.FILLED)
            font = cv2.FONT_HERSHEY_DUPLEX
            cv2.putText(frame, name, (left + 6, bottom - 6), font, 1.0, (255, 255, 255), 1)

        cv2.imshow('Video', frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    video_capture.release()
    cv2.destroyAllWindows()
