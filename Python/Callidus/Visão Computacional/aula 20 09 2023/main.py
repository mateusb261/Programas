import keras

from keras.models import Sequential, load_model
from keras.layers import Dense, Dropout, Conv2D, MaxPooling2D, Flatten
from keras.optimizers import Adam


# Criando a inteligencia

class Brain():
    def _init_(self, iS=(100, 100, 3), lr=0.0005):
        self.learningRate = lr
        self.inputShape = iS
        self.numOutputs = 4
        self.model = Sequential()

        # Criando as camadas da CNN
        self.model.add(Conv2D(32, (3, 3), activation='relu', input_shape=self.inputShape))
        self.model.add(MaxPooling2D((2, 2)))
        self.model.add(Conv2D(64, (2, 2), activation='relu'))

        # Camada redisionamento
        self.model.add(Flatten())

        # camada MLP
        self.model.add(Dense(units=256, activation='relu'))
        self.model.add(Dense(units=self.numOutputs))

        # Compilando o modelo
        self.model.compile(loss='mean_squared_error', optimizer=Adam(lr=self.learningRate))

    # Carregamento de rede treinada
    def loadModel(self, filepath):
        self.model = load_model(filepath)
        return self.model