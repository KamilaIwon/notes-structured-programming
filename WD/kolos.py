import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#zad1

name = np.array([['Anna', 'Zofia', 'Sylwia', 'Katarzyna', 'Teresa', 'Tomasz', 'Cezary', 'Zenon', 'Filip', 'Adrian']])
age = np.array([[21,40,13,31,34,14,13,28,20,15]])
sex = np.array([['K', 'K', 'K', 'K', 'K', 'M', 'M', 'M', 'M', 'M']])
weight = np.array([[65,80,64,69,74,61,66,61,69,77]])
height = np.array([[179,179,151,177,170,157,151,153,160,160]])
glasses = np.array([[False,True,False,True,False,True,False,True,False,True]])

print('osoby naszące okulary: ')
print(name[glasses])

print('\nile kobiet nosi okulary: ')
ile = (name[(glasses)*(sex == 'K')])
print(len(ile))

print('\nosoby o wzroscie [160,180] noszace okulary')
ile1 = (name[(160<=height)*(height<=180)*(glasses)])
print(ile1)

print('\nBMI:')
bmi = weight*1000/height**2
print(bmi.round(decimals=2))

print('\nsredni wiek mezczyn noszacych okulary:')
print((age[(sex=='M')*(glasses)]).mean())
print('\nsredni wiek kobiet nienoszacych okularów:')
print((age[(sex=="K")*(glasses==False)]).mean())

#zad2

x = np.linspace(0,2,100)
y1 = np.exp(x)
y2 = x**x
plt.plot(x,y1,'blue',linestyle='-',label='exp(x)')
plt.plot(x,y2,'red',linestyle='--',label='x**x')
plt.legend(title='wykres')
plt.show()

#zad3


wyniki = pd.read_csv('wyniki.csv',sep=';', index_col=0, encoding="UTF-8")

#a
wyborcy = wyniki['Liczba wyborców uprawnionych do głosowania']
wyniki['wyborcy']=wyborcy
print(wyniki[wyborcy==wyborcy.max()])

#b
glos = wyniki[(wyniki['Województwo']=='warmińsko-mazurskie')]
glos1 = glos.iloc[:,23:-2:]
index = glos1.idxmax(axis=1)
print(index)

#c
wyniki.plot.bar(x = 'Województwo', y = 'Andrzej Sebastian DUDA')
wyniki.plot.bar(x='Województwo',y='Rafał Kazimierz TRZASKOWSKI')

kando0=wyniki.iloc[:,25:-2:3]
kando0['Polska']=kando0.sum(axis=1)
print(kando0)
kando0.sort_values('Polska',ascending=False).iloc[:,0:-1:2].plot.bar(stacked=True)
plt.show()