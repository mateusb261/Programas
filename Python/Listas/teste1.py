from clientes import Cliente
from contas2 import Conta
joão = Cliente("João da Silva", "777-1234")
maria = Cliente("Maria da Silva", "555-4321")
conta_joão_maria = Conta([joão, maria], 123, 2000)
conta_joão_maria.saque(3000)
resumo_joão_maria = conta_joão_maria.resumo()
print(resumo_joão_maria)