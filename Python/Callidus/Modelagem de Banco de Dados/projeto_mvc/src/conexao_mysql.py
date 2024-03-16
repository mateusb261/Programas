
import mysql.connector

class Conexao():
  def __init__(self):
    super(Conexao, self).__init__()
  
  def conectar(self):
    self.conexao = mysql.connector.connect(
        host = '127.0.0.1',
        user = 'root',
        password = '@1Sql',
        database = 'produto'
    )
    return self.conexao
