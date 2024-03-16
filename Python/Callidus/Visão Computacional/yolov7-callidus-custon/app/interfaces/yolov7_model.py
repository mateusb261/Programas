import torch
from torchvision import transforms
from utils.datasets import letterbox
from utils.general import non_max_suppression, scale_coords
from models.experimental import attempt_load

import numpy as np


class yolov7_model:
	"""
	Classe utilizada para carregar um modelo yoloV7 e realizar a predição em uma imagem
	"""
	def __init__(self,model_path,img_size = 640,stride = 64,conf_thres = 0.25,iou_thres = 0.45):
		"""
		Método init da classe
		"""
		self.conf_thres = conf_thres # Nível de certeza necessário para confirmar a detecção
		self.iou_thres = iou_thres   # Relação utilizada para realizar detecções sobre-postas
		self.img_size = img_size     # Tamanho da imagem de entrada da rede carregada
		self.stride = stride
		self.device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu") # Identificação do dispositivo de processsamento disponível
		self.half = self.device.type != "cpu"
		# Carregando modelo
		self.model = attempt_load(model_path, map_location=self.device)
		self.class_names = self.model.module.names if hasattr(self.model, 'module') else self.model.names # Obteção dos nomes das classes
		# Carrergando modelo com a metada da precisão
		if self.half:
			self.model = self.model.half()
		else:
			self.model = self.model.float()
	def processFrame(self,image):
		"""
		Método utilizado para realizar a detecção da rede em uma imagem
		"""
		shape_im0 = image.shape
		image = letterbox(image, self.img_size, stride = self.stride, auto = True)[0]

		image = transforms.ToTensor()(image)
		image = torch.tensor(np.array([image.numpy()]))

		image = image.to(self.device)
		image = image.half() if self.half else image.float()
		with torch.no_grad():
			output = self.model(image)[0]
		output = non_max_suppression(output, self.conf_thres, self.iou_thres, classes=None, agnostic=False)
		detect = [];
		for i, det in enumerate(output):
			det[:, :4] = scale_coords(image.shape[2:], det[:, :4], shape_im0).round()
			detect.append(det.detach().cpu().numpy())
		return detect[0]