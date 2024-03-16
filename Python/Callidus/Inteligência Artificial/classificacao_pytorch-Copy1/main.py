import torch
from torch import nn, optim

from torchvision import datasets
from torchvision import transforms

from torch.utils.data import DataLoader

import matplotlib.pyplot as plt
import numpy as np
import time


args = {
    'batch_size': 50,
    'num_workers': 4,
    'num_classes': 10,
    'lr': 1e-4,
    'weight_decay': 5e-4,
    'num_epochs': 30
}

if torch.cuda.is_available():
  args['device'] = torch.device('cuda')
else:
  args['device'] = torch.device('cpu')

print(args['device'])


train_set = datasets.MNIST('./',
                           train=True,
                           transform=transforms.ToTensor(),
                           download=True)

test_set = datasets.MNIST('./',
                           train=False,
                           transform=transforms.ToTensor(),
                           download=False)

print('Amostras de treino: ' + str(len(train_set)) + '\nAmostras de Teste:' + str(len(test_set)))


print(type(train_set))
print(type(train_set[0]))


for i in range(3):
    dado, rotulo = train_set[i]

    plt.figure()
    plt.imshow(dado[0])
    plt.title('Rotulo: '+ str(rotulo))


crop_set = datasets.MNIST('./',
                          train=False,
                          transform=transforms.RandomCrop(12),
                          download=False)

# Tuple (dado, rótulo)
for i in range(3):
    dado, rotulo = crop_set[0]

    plt.figure()
    plt.imshow(dado)
    plt.title('Rótulo: ' + str(rotulo))


train_loader = DataLoader(train_set,
                          batch_size=args['batch_size'],
                          shuffle=True,
                          num_workers=args['num_workers'])

test_loader = DataLoader(test_set,
                          batch_size=args['batch_size'],
                          shuffle=True,
                          num_workers=args['num_workers'])

for batch in train_loader:
    dado, rotulo = batch
    print(dado.size(), rotulo.size())

    plt.imshow(dado[0][0])
    plt.title('Rotulo: ' + str(rotulo[0]))
    break


class MLP(nn.Module):

    def __init__(self, input_size, hidden_size, out_size):
        super(MLP, self).__init__()

        self.features = nn.Sequential(
            nn.Linear(input_size, hidden_size),
            nn.ReLU(),
            nn.Linear(hidden_size, hidden_size),
            nn.ReLU()
        )
        self.out = nn.Linear(hidden_size, out_size)
        self.softmax = nn.Softmax()

    def forward(self, X):
        X = X.view(X.size(0), -1)

        feature = self.features(X)
        output = self.softmax(self.out(feature))

        return output


input_size = 28 * 28
hidden_size = 128
out_size = 10  # classes

torch.manual_seed(42)
net = MLP(input_size, hidden_size, out_size).to(args['device'])  # cast na GPU


criterion = nn.CrossEntropyLoss().to(args['device'])
optimizer = optim.Adam(net.parameters(), lr=args['lr'], weight_decay=args['weight_decay'])


print(args['device'])

for epoch in range(args['num_epochs']):
    start = time.time()

    epoch_loss = []

    for batch in train_loader:
        dado, rotulo = batch

        # Cast na GPU
        dado = dado.to(args['device'])
        rotulo = rotulo.to(args['device'])

        # Forward
        pred = net(dado)
        loss = criterion(pred, rotulo)
        epoch_loss.append(loss.cpu().data)

        # Backward
        loss.backward()
        optimizer.step()

    epoch_loss = np.asarray(epoch_loss)

    val_epoch_loss = []

    for batch in test_loader:
        dado, rotulo = batch

        # cast na GPU

        dado = dado.to(args['device'])
        rotulo = rotulo.to(args['device'])

        # Forward
        pred = net(dado)
        loss = criterion(pred, rotulo)
        val_epoch_loss.append(loss.cpu().data)

    val_epoch_loss = np.asarray(val_epoch_loss)

    end = time.time()

    print("Epoca %d, Loss: %.4f, Val_Loss %.4f, +\- %.4f, Tempo: %.2f" % (
    epoch, epoch_loss.mean(), val_epoch_loss.mean(), epoch_loss.std(), end - start))


def acuracia_rede(predict, rotulo):
    predict = predict.cpu().tolist()
    rotulo = rotulo.cpu().tolist()

    len_batch = len(predict)

    acertos = 0

    for i in range(len_batch):
        if predict[i] == rotulo[i]:
            acertos += 1

    print(acertos / len_batch)


for batch in test_loader:
    dado, rotulo = batch

    # cast na GPU

    dado = dado.to(args['device'])
    rotulo = rotulo.to(args['device'])

    pred = net(dado)

    predicted_class = torch.argmax(pred, dim=1)

    # print(predicted_class.to('cpu').data)

    plt.figure()
    plt.imshow(dado.to('cpu').data[0][0])
    plt.title('Rotulo: ' + str(predicted_class[0]))
    acuracia_rede(predicted_class, rotulo)
    # print(pred)
    break


