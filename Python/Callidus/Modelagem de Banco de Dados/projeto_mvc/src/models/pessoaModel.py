
import sys
from pathlib import Path
file = Path(__file__).resolve()
parent, root = file.parent, file.parents[1]
sys.path.append(str(root))

from PyQt5.uic import loadUi
from PyQt5 import uic, QtWidgets
from PyQt5.QtWidgets import QMessageBox, QApplication, QMainWindow
from PyQt5.QtCore import *
from src.conexao_mysql import Conexao

class PessoaModel(QMainWindow):
    def __init__(self):
        super(PessoaModel, self).__init__()
    
    def inserir_produto(self, descricao, preco, estoque):
        self.descricao = descricao
        self.preco = preco
        self.estoque = estoque
        self.sql = '''INSERT INTO PRODUTO (DESCRICAO, PRECO, ESTOQUE) VALUES ('{}', '{}', '{}' 
                ) '''.format(self.descricao, self.preco, self.estoque)
        self.conexao = Conexao().conectar()
        self.cursor = self.conexao.cursor()
        self.cursor.execute(self.sql)
        self.conexao.commit()
        self.cursor.close()

    def alterar_produto(self, descricao, preco, estoque, id):
        self.id = id
        self.descricao = descricao
        self.preco = preco
        self.estoque = estoque
        self.sql = sql = '''UPDATE PRODUTO SET DESCRICAO = '{}', PRECO = '{}' , ESTOQUE = '{}' 
                WHERE ID = '{}' '''.format(self.descricao, self.preco, self.estoque, self.id)
        self.conexao = Conexao().conectar()
        self.cursor = self.conexao.cursor()
        self.cursor.execute(self.sql)
        self.conexao.commit()
        self.cursor.close()

    def excluir_produto(self, id):
        self.id = id
        self.sql = '''DELETE FROM PRODUTO WHERE ID = '{}' '''.format(self.id) 
        self.conexao = Conexao().conectar()
        self.cursor = self.conexao.cursor()
        self.cursor.execute(self.sql)
        self.conexao.commit()
        self.cursor.close()
  
    def pesquisar_produto_por_id(self, id):
        self.id = id
        if self.id != '':
            self.sql = '''SELECT * FROM PRODUTO WHERE ID = '{}' '''.format(self.id)        
        else:
            self.sql = 'SELECT * FROM PRODUTO'
        self.conexao = Conexao().conectar()
        self.cursor = self.conexao.cursor()
        self.cursor.execute(self.sql)
        self.dados = self.cursor.fetchall()
        self.cursor.close()
        return self.dados         
    
    def pesquisar_produto_por_descricao(self, descricao):
        self.descricao = descricao
        if self.descricao != '':
            self.sql = '''SELECT * FROM PRODUTO WHERE DESCRICAO LIKE '{}' '''.format('%'+self.descricao+'%')        
        else:
            self.sql = 'SELECT * FROM PRODUTO'        
        self.conexao = Conexao().conectar()
        self.cursor = self.conexao.cursor()
        self.cursor.execute(self.sql)
        self.dados = self.cursor.fetchall()
        self.cursor.close()
        return self.dados
    
    def pesquisar_produto_por_preco(self, preco):
        self.preco = preco
        if self.descricao != '':
            self.sql = '''SELECT * FROM PRODUTO WHERE PRECO = '{}' '''.format('%'+self.preco+'%')
        else:
            self.sql = 'SELECT * FROM PRODUTO'         
        self.conexao = Conexao().conectar()
        self.cursor = self.conexao.cursor()
        self.cursor.execute(self.sql)
        self.dados = self.cursor.fetchall()
        self.cursor.close()
        return self.dados    
    
    def pesquisar_produto_por_estoque(self, estoque):
        self.estoque = estoque
        if self.descricao != '':
            self.sql = '''SELECT * FROM PRODUTO WHERE ESTOQUE = '{}' '''.format('%'+self.estoque+'%')
        else:
            self.sql = 'SELECT * FROM PRODUTO'            
        self.conexao = Conexao().conectar()
        self.cursor = self.conexao.cursor()
        self.cursor.execute(self.sql)
        self.dados = self.cursor.fetchall()
        self.cursor.close()
        return self.dados    