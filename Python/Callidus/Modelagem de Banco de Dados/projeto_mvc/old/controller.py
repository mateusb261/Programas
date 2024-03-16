
from model import Model
from view import View

class Controller:
    def __init__(self):
        self.model = Model()
        self.view = View()

    def main(self):
        print('In main of controller.')
    
if __name__ == '__main__':
    controll = Controller()
    controll.main()