
from PyQt5 import uic, QtWidgets
from PyQt5.QtWidgets import QMessageBox
import mysql.connector
from PyQt5.QtCore import *

conexao = mysql.connector.connect(
    host = '127.0.0.1',
    user = 'root',
    password = 'Fvieira',
    database = 'produto'
)

id_selecionado = 0
operacaoIncluir = False

def pesquisar():
    parametro = formulario.lineEditFiltro.text().upper()
    indice = formulario.comboBoxFiltro.currentIndex()

    match indice:
        case 0: 
            sql = '''SELECT * FROM PRODUTO WHERE ID = '{}' '''.format(parametro)
        case 1:
            sql = '''SELECT * FROM PRODUTO WHERE DESCRICAO LIKE '{}' '''.format('%'+parametro+'%')
        case 2:
            sql = '''SELECT * FROM PRODUTO WHERE PRECO = '{}' '''.format(parametro)
        case 3:
            sql = '''SELECT * FROM PRODUTO WHERE ESTOQUE = '{}' '''.format(parametro)
        case _:
            formulario.lineEditFiltro.setText("Valor {} inválido".format(indice))

    if formulario.lineEditFiltro.text() != '':
       atualizar(str(sql))
    else:
       atualizar('')  
    
    limparCampo()

    #formulario.lineEditFiltro.setText(formulario.comboBoxFiltro.currentText())
    #formulario.lineEditFiltro.setText(str(formulario.comboBoxFiltro.currentIndex()))    
    #exibirMensagem("Busca", "SELECT * FROM PRODUTO")
    #formulario.lineEditFiltro.setText(str(sql))    

def selecionarFiltro():
    formulario.lineEditFiltro.clear()    

def carregarFiltro():
    formulario.comboBoxFiltro.clear()
    formulario.comboBoxFiltro.addItem('ID')
    formulario.comboBoxFiltro.addItem('DESCRIÇÃO')
    formulario.comboBoxFiltro.addItem('PREÇO')
    formulario.comboBoxFiltro.addItem('ESTOQUE')

def carregarDadosFormulario():
    linha = formulario.tableWidgetGrid.currentRow()
    formulario.lineEditID.setText(str(formulario.tableWidgetGrid.item(linha, 0).text()))
    formulario.lineEditDescricao.setText(str(formulario.tableWidgetGrid.item(linha, 1).text()))
    formulario.lineEditPreco.setText(str(formulario.tableWidgetGrid.item(linha, 2).text()))
    formulario.lineEditEstoque.setText(str(formulario.tableWidgetGrid.item(linha, 3).text()))    

def atualizar(filtroSQL):
    if filtroSQL != '':
       sql = filtroSQL
    else:
       sql = 'SELECT * FROM PRODUTO'
       carregarFiltro()   

    cursor = conexao.cursor()
    #sql = 'SELECT * FROM PRODUTO' 
    cursor.execute(sql)
    dados = cursor.fetchall() #matrizComValores
    #lista.tableWidget.setRowCount(1)
    formulario.tableWidgetGrid.setRowCount(len(dados))
#    formulario.tableWidgetGrid.setColumnCount(len(dados))
    formulario.tableWidgetGrid.setColumnCount(4)

    for i in range(0, len(dados)):
        for j in range(0, 4):
            formulario.tableWidgetGrid.setItem(i, j, QtWidgets.QTableWidgetItem(str(dados[i][j])))


def habilitarEdicao():
    formulario.commandLinkButtonNovo.setEnabled(False)
    formulario.commandLinkButtonEditar.setEnabled(False)    
    formulario.commandLinkButtonSalvar.setEnabled(True)    
    formulario.commandLinkButtonExcluir.setEnabled(False)    
    formulario.commandLinkButtonCancelar.setEnabled(True) 

    formulario.lineEditID.setEnabled(False)
    formulario.lineEditDescricao.setEnabled(True)
    formulario.lineEditPreco.setEnabled(True)
    formulario.lineEditEstoque.setEnabled(True)   

    formulario.tableWidgetGrid.setEnabled(False) 
    formulario.lineEditID.setFocus()

def desabilitarEdicao():
    formulario.commandLinkButtonNovo.setEnabled(True)
    formulario.commandLinkButtonEditar.setEnabled(True)    
    formulario.commandLinkButtonSalvar.setEnabled(False)    
    formulario.commandLinkButtonExcluir.setEnabled(True)    
    formulario.commandLinkButtonCancelar.setEnabled(True) 

    formulario.lineEditID.setEnabled(False)
    formulario.lineEditDescricao.setEnabled(False)
    formulario.lineEditPreco.setEnabled(False)
    formulario.lineEditEstoque.setEnabled(False)  

    formulario.tableWidgetGrid.setEnabled(True)         

def limparCampo():
    formulario.lineEditID.clear()
    formulario.lineEditDescricao.clear()
    formulario.lineEditPreco.clear()
    formulario.lineEditEstoque.clear()    

def incluir():
    global operacaoIncluir
    operacaoIncluir = True
    limparCampo()
    habilitarEdicao()

def editar():
   global operacaoIncluir
   operacaoIncluir = False
   if formulario.lineEditID.text() != '':
       habilitarEdicao()
   else:
       exibirMensagem("Aviso", "Não há registro selecionado!")

def salvar():
    global operacaoIncluir
    mensagem = ''

    id = formulario.lineEditID.text().upper()
    descricao = formulario.lineEditDescricao.text().upper()
    preco = formulario.lineEditPreco.text().upper()
    estoque = formulario.lineEditEstoque.text().upper()
    #if id != '' and descricao != '' and preco != '' and estoque != '':
    if operacaoIncluir:
       sql = '''INSERT INTO PRODUTO (DESCRICAO, PRECO, ESTOQUE) VALUES ('{}', '{}', '{}' 
                ) '''.format(descricao, preco, estoque)
       mensagem = 'Registro incluído!'
    else:
       sql = '''UPDATE PRODUTO SET DESCRICAO = '{}', PRECO = '{}' , ESTOQUE = '{}' 
                WHERE ID = '{}' '''.format(descricao, preco, estoque, id)           
       mensagem = 'Registro alterado!'

    cursor = conexao.cursor()
    cursor.execute(sql)
    conexao.commit()
    cursor.close()
    
    atualizar('')
    desabilitarEdicao()
    exibirMensagem("Aviso", str(mensagem))    
    limparCampo()

def excluir():
   if formulario.lineEditID.text() != '':
      cursor = conexao.cursor()
      id = formulario.lineEditID.text()
      sql = '''DELETE FROM PRODUTO WHERE ID = '{}' '''.format(id)
      cursor.execute(sql)
      conexao.commit()
      cursor.close()
      limparCampo()
      exibirMensagem("Aviso", "Registro excluído!")
      atualizar('')
   else:
       exibirMensagem("Aviso", "Não há registro selecionado!")    


def cancelar():
    global operacaoIncluir
    operacaoIncluir = False
    desabilitarEdicao()
    QMessageBox.information(QMessageBox(), 'Título', 'Corpo da mensagem')

def carregarFormulario():
    formulario.show()
    desabilitarEdicao()
    atualizar('')

def exibirMensagem(titulo, texto):
    QMessageBox.about(produto, titulo, texto)
    #QMessageBox.information(QMessageBox(), 'Título', 'Corpo da mensagem')

def cadastrar():
    cadastro.show()

def carregarFormularioProduto():
    produto.show()


app = QtWidgets.QApplication([])
home = uic.loadUi('home.ui')

cadastro = uic.loadUi('cadastro.ui')
relatorio = uic.loadUi('relatorio.ui')
produto = uic.loadUi('produto.ui')
formulario = uic.loadUi('formularioPadrao.ui')

home.actionCadastroProduto.triggered.connect(cadastrar)
home.actionProduto.triggered.connect(carregarFormularioProduto)
home.actionFormularioPadrao.triggered.connect(carregarFormulario)
#produto.pushButtonMensagem.clicked.connect(chamaMensagem)
formulario.commandLinkButtonNovo.clicked.connect(incluir)
formulario.commandLinkButtonEditar.clicked.connect(editar)
formulario.commandLinkButtonSalvar.clicked.connect(salvar)
formulario.commandLinkButtonExcluir.clicked.connect(excluir)
formulario.commandLinkButtonCancelar.clicked.connect(cancelar)
formulario.tableWidgetGrid.clicked.connect(carregarDadosFormulario)
formulario.pushButtonFiltro.clicked.connect(pesquisar)
formulario.comboBoxFiltro.currentTextChanged.connect(selecionarFiltro)

home.show()
app.exec()