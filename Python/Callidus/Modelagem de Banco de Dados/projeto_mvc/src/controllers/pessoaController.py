
import sys
from pathlib import Path
file = Path(__file__).resolve()
parent, root = file.parent, file.parents[1]
sys.path.append(str(root))

from PyQt5.uic import loadUi
from PyQt5 import uic, QtWidgets
from PyQt5.QtWidgets import QMessageBox, QApplication, QMainWindow
from PyQt5.QtCore import *
#from conexao_mysql import Conexao
from src.models.pessoaModel import PessoaModel

operacaoInserir = False

class PessoaController(QMainWindow):  
    def __init__(self):
        super(ProdutoController, self).__init__()
        self.produto = loadUi('src/views/produtoView.ui')
        self.produto.comboBoxFiltro.currentTextChanged.connect(self.selecionar_filtro)
        self.produto.tableWidgetGrid.clicked.connect(self.carregar_dados_formulario)        
        self.produto.pushButtonFiltro.clicked.connect(self.pesquisar_produto)
        self.produto.commandLinkButtonNovo.clicked.connect(self.inserir_produto)
        self.produto.commandLinkButtonEditar.clicked.connect(self.alterar_produto)
        self.produto.commandLinkButtonSalvar.clicked.connect(self.salvar_produto)
        self.produto.commandLinkButtonExcluir.clicked.connect(self.excluir_produto)
        self.produto.commandLinkButtonCancelar.clicked.connect(self.cancelar_produto)
     
    def pesquisar_produto(self):
        self.indice_combobox = self.produto.comboBoxFiltro.currentIndex()
        self.parametro_busca = self.produto.lineEditFiltro.text().upper()    
        self.produtoModel = PessoaModel
        self.limpar_campo()        
        match self.indice_combobox:
            case 0: 
                self.dados = self.produtoModel.pesquisar_produto_por_id(self, str(self.parametro_busca))
            case 1:
                self.dados = self.produtoModel.pesquisar_produto_por_descricao(self, str(self.parametro_busca))
            case 2:
                self.dados = self.produtoModel.pesquisar_produto_por_preco(self, str(self.parametro_busca))
            case 3:
                self.dados = self.produtoModel.pesquisar_produto_por_estoque(self, str(self.parametro_busca))
            case _:
                QMessageBox.information(QMessageBox(), 'Título', "Valor {} inválido".format(self.indice))

        self.produto.tableWidgetGrid.setRowCount(len(self.dados))
        self.produto.tableWidgetGrid.setColumnCount(4)

        for i in range(0, len(self.dados)):
            for j in range(0, 4):
                self.produto.tableWidgetGrid.setItem(i, j, QtWidgets.QTableWidgetItem(str(self.dados[i][j])))        

    def inserir_produto(self):
        global operacaoInserir
        operacaoInserir = True
        self.limpar_campo()
        self.habilitar_edicao()

    def alterar_produto(self):
        global operacaoInserir
        operacaoInserir = False
        if self.produto.lineEditID.text() != '':
            self.habilitar_edicao()
        else:
            QMessageBox.information(QMessageBox(), 'Aviso', "Não há registro selecionado!")

    def salvar_produto(self):
        global operacaoInserir
        self.id = self.produto.lineEditID.text().upper()
        self.descricao = self.produto.lineEditDescricao.text().upper()
        self.preco = self.produto.lineEditPreco.text().upper()
        self.estoque = self.produto.lineEditEstoque.text().upper()
        self.produtoModel = PessoaModel
        #if id != '' and descricao != '' and preco != '' and estoque != '':
        if operacaoInserir:
            self.produtoModel.inserir_produto(self, str(self.descricao), str(self.preco), str(self.estoque))
            QMessageBox.information(QMessageBox(), 'Aviso', 'Registro incluído!')
        else:
            self.produtoModel.alterar_produto(self, str(self.descricao), str(self.preco), str(self.estoque), str(self.id))
            QMessageBox.information(QMessageBox(), 'Aviso', 'Registro alterado!')

        self.pesquisar_produto()
        self.desabilitar_edicao()
        self.limpar_campo()

    def excluir_produto(self):
        self.id = self.produto.lineEditID.text().upper()
        self.produtoModel.excluir_produto(self, str(self.id))
        QMessageBox.information(QMessageBox(), 'Aviso', 'Registro excluído!')
        self.limpar_campo()
        self.pesquisar_produto()

    def cancelar_produto(self):
        global operacaoInserir
        operacaoInserir = False
        self.desabilitar_edicao()

    def carregar_produto(self):
        self.produto.show()
        self.carregar_filtro()


    def selecionar_filtro(self):
        self.produto.lineEditFiltro.clear()    
    
    def carregar_filtro(self):
        self.produto.comboBoxFiltro.clear()
        self.produto.comboBoxFiltro.addItem('ID')
        self.produto.comboBoxFiltro.addItem('DESCRIÇÃO')
        self.produto.comboBoxFiltro.addItem('PREÇO')
        self.produto.comboBoxFiltro.addItem('ESTOQUE')

    def carregar_dados_formulario(self):
        linha = self.produto.tableWidgetGrid.currentRow()
        self.produto.lineEditID.setText(str(self.produto.tableWidgetGrid.item(linha, 0).text()))
        self.produto.lineEditDescricao.setText(str(self.produto.tableWidgetGrid.item(linha, 1).text()))
        self.produto.lineEditPreco.setText(str(self.produto.tableWidgetGrid.item(linha, 2).text()))
        self.produto.lineEditEstoque.setText(str(self.produto.tableWidgetGrid.item(linha, 3).text()))  

    def habilitar_edicao(self):
        self.produto.commandLinkButtonNovo.setEnabled(False)
        self.produto.commandLinkButtonEditar.setEnabled(False)    
        self.produto.commandLinkButtonSalvar.setEnabled(True)    
        self.produto.commandLinkButtonExcluir.setEnabled(False)    
        self.produto.commandLinkButtonCancelar.setEnabled(True) 

        self.produto.lineEditID.setEnabled(False)
        self.produto.lineEditDescricao.setEnabled(True)
        self.produto.lineEditPreco.setEnabled(True)
        self.produto.lineEditEstoque.setEnabled(True)   

        self.produto.tableWidgetGrid.setEnabled(False) 
        self.produto.lineEditID.setFocus()

    def desabilitar_edicao(self):
        self.produto.commandLinkButtonNovo.setEnabled(True)
        self.produto.commandLinkButtonEditar.setEnabled(True)    
        self.produto.commandLinkButtonSalvar.setEnabled(False)    
        self.produto.commandLinkButtonExcluir.setEnabled(True)    
        self.produto.commandLinkButtonCancelar.setEnabled(True) 

        self.produto.lineEditID.setEnabled(False)
        self.produto.lineEditDescricao.setEnabled(False)
        self.produto.lineEditPreco.setEnabled(False)
        self.produto.lineEditEstoque.setEnabled(False)  

        self.produto.tableWidgetGrid.setEnabled(True)         

    def limpar_campo(self):
        self.produto.lineEditID.clear()
        self.produto.lineEditDescricao.clear()
        self.produto.lineEditPreco.clear()
        self.produto.lineEditEstoque.clear()    