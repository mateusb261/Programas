
import sys
from pathlib import Path
file = Path(__file__).resolve()
parent, root = file.parent, file.parents[1]
sys.path.append(str(root))

from PyQt5.uic import loadUi
from PyQt5 import uic, QtWidgets
from PyQt5.QtWidgets import QMessageBox, QApplication, QMainWindow
from PyQt5.QtCore import *
from src.controllers.produtoController import ProdutoController

class Main(QMainWindow):
    def __init__(self):
        super(Main, self).__init__()
        loadUi('src/views/mainView.ui', self)
        self.actionProduto.triggered.connect(self.carregar_produto)
        self.actionProduto.triggered.connect(self.carregar_produto)

    def carregar_produto(self):
        self.produto = ProdutoController()
        self.produto.carregar_produto()

    def carregar_pessoa(self):
        self.produto = ProdutoController()
        self.produto.carregar_produto()
        
if __name__ == "__main__":
    app = QApplication(sys.argv)
    myapp = Main()
    myapp.show()
    sys.exit(app.exec_())
