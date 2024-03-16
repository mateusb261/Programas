import cv2

from app.cameo.managers import CaptureManager, WindowManager
from app.utils.utils import onImage, labelDraw,labelDrawOneDetect,roi,load_image,batch_image
from app.modelos.inteligencia import Classificador
import numpy as np

# dicionario utilizado para determinar a cor do retângulo delimitador
dict = {'nei':(255, 0, 0),
        'leticia':(255,0,255)}
dictepi = {0: (255, 0, 0),
           1: (0,255,0),
           2: (0,0,255),
           3: (255,0,255),
           4: (0,255,255),
           5: (123,255,0),
           6: (255,123,0),
           7: (50,12,200),
           8: (255,34,200),
           9: (125,0,85)}

class Cameo(object):
    """
    Objeto cameo utilizado para gerenciar a câmera
    """
    def __init__(self,model = None):
        """
        Inicialização do modelo cameo que pode receber um modelo yolov7
        para deteção
        """
        self.model = model # Modelo yoloV7
        self.class_names = model.class_names #Nome das classes do modelo
        self._windowManager = WindowManager('Cameo',
                                            self.onKeypress) # Manager da tela do modelo
        self._captureManager = CaptureManager(
            cv2.VideoCapture(0), self._windowManager, True) # Gerenciador da janela de vídeo

    def run(self):
        """
        Método da classe cameo que é utilizado apenas para imprimir a imagem sem a câmera
        """
        self._windowManager.createWindow()
        while self._windowManager.isWindowCreated:
            self._captureManager.enterFrame()
            frame = self._captureManager.frame

            if frame is not None:
                # Trecho para adicionar código personalização para aplicação.
                detects = onImage(frame,self.model) # Método utilizado para realizar a detecção do objeto em uma imagem
                print(detects)
                for detect in detects:
                    label = self.class_names[int(detect[5])]
                    color_rec = dictepi[int(detect[5])]
                    labelDrawOneDetect(frame,detect,label,color_rec = color_rec) # Desenho do label da classificação em cada predição
            self._captureManager.exitFrame()
            self._windowManager.processEvents()
    
    def run_object(self,classificador):
        """
        Método cameo utilizado para rodar o projeto com o cameo, detector e classificador
        """
        self._windowManager.createWindow()
        while self._windowManager.isWindowCreated:
            self._captureManager.enterFrame()
            frame = self._captureManager.frame

            detects = onImage(frame,self.model) # Método utilizado para realizar a detecção do objeto em uma imagem
            dataset_frame = np.array([])
           
            for detect in detects:
                image = roi(frame,detect) # Método utilizado para retirar a região de interesse da imagem a partir da detecção do yolov7
                image = load_image(image,classificador.model.input_size) # Método utilizado para ajustar o tamanho da região de interesse para o tamenho de entrada da rede
                dataset_frame = np.append(dataset_frame,image) # Método utilizado para criar um dataset
                dataset_frame = batch_image(dataset_frame,classificador.model.input_size) # Método de geração de bachts
            if len(detects) > 0:
                classes,conf,_ = classificador.predict(dataset_frame) # Pedrição de todas as detecções do toloV7
                print(classes,conf) # Print da classe e da confiação da detecção
                for detect,label in zip(detects,classes):# Criação do objeto itereator para iterar as predições
                    labelDrawOneDetect(frame,detect,label,color_rec = dict[label]) # Desenho do label da classificação em cada predição

            self._captureManager.exitFrame()
            self._windowManager.processEvents()

    def onKeypress(self, keycode):
        """Handle de teclado.

        space  -> Faz um screenshot.
        tab    -> Finaliza/iniciar a captura em vídeo.
        escape -> Finaliza o programa.

        """
        if keycode == 32: # space
            self._captureManager.writeImage('screenshot.png')
            self._captureManager.startWritingVideo(
                    'screencast.avi')
        elif keycode == 9: # tab
            if not self._captureManager.isWritingVideo:
                self._captureManager.startWritingVideo(
                    'screencas.avi')
            else:
                self._captureManager.stopWritingVideo()
        elif keycode == 27: # escape
            self._captureManager.close_can()
            self._windowManager.destroyWindow()

if __name__ == '__main__':
	Cameo().run()
