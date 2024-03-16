import cv2
from app.interfaces.yolov7_model import yolov7_model
from app.cameo.cameo import Cameo
from app.modelos.inteligencia import Classificador


if __name__ == '__main__':
	model = yolov7_model('weigths/detect_epi.pt',conf_thres = 0.3,iou_thres = 0.5)
	#classificador = Classificador(diretory = None)
	#classificador.load_model("registro_de_face/weigths/classificador2")
	cameo = Cameo(model)
	#cameo.run_object(classificador)
	cameo.run()
