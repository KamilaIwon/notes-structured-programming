# Iwon Kamila 164933 wariant 16
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# zad1

nazwa = np.array([['Amazonka', 'Nil', 'Jangcy', 'Missisipi-Missouri', 'Huang He', 'Ob Irtysz', 'Kongo', 'Mekong', 'Amur', 'Lena', 'Parana', 'Mackanzie', 'Niger', 'Jenisej', 'Wołga']])
kontynent = np.array([['Ameryka Poludniowa', 'Afryka', 'Eurazja', 'Ameryka Polnocna', 'Eurazja', 'Eurazja', 'Afryka', 'Eurazja', 'Eurazja', 'Eurazja', 'Ameryka Poludniowa', 'Ameryka Polnocna', 'Afryka', 'Eurazja', 'Eurazja']])
dlugosc = np.array([[7040, 6695, 6300, 6020, 5464, 5410, 4700, 4500, 4440, 4400,4380, 4240, 4160, 4102, 3530]])
powierzchnia = np.array([7200, 2870, 1807, 3229, 752, 2972, 3690, 810, 1855, 2490, 3100, 1760, 2117, 2580, 1360])
liczbapanstw = np.array([[3, 7, 1, 1, 1, 3, 3, 6, 3, 1, 3, 1, 4, 2, 2]])

# ile rzek jest w tabelce
print(nazwa.size)

# ktore plyna przez dokladnie 3 panstwa
print((nazwa[(liczbapanstw == 3)]))

# ile rzek ma dlugosc mniej niz 5000km
print(len(nazwa[(dlugosc < 5000)]))

# zaczyna sie na litere M
litera = np.char.startswith(nazwa, "M")
print(nazwa[litera])

# sortowanie powierzchni
sorted_array = np.sort(powierzchnia)
powierzchnia = sorted_array[::-1]
print(powierzchnia)
print(nazwa)

# nazwy rzek z powierzchnia>2000 i z Ameryki
print(nazwa[(powierzchnia > 2000) * ((kontynent == 'Ameryka Polnocna') | (kontynent == 'Ameryka Poludniowa'))])

# zad2

x = np.linspace(-1, 3, 100)
y1 = np.exp(x)
y2 = np.exp(2*x)
fig, axs = plt.subplots(2)
fig.suptitle('Wykresy')
axs[0].plot(x, y1, 'blue', linestyle='-', label='exp(x)')
axs[1].plot(x, y2, 'red', linestyle='--', label='exp(2*x)')
fig.legend(title='wykres')
plt.show()

# zad3

#wczytanie danych
data = pd.read_csv('penguins.csv', index_col=None, encoding="UTF-8")
print(data)

# srednia waga pingwinow chinstrap
print(data[data['species'] == 'Chinstrap']['body_mass_g'].mean())

# wykres kolowy ilosci pingwinow na kazdej wyspie
ilosc = (data.groupby(by='island').size())
wykres1 = data.groupby(['island']).size().plot.pie()
plt.show()

# wykres pudelkowy zaleznosci wagi pingwina od gatunku
print(data.groupby(by=['species'])['body_mass_g'].mean())
a = (data[data['species'] == 'ChinStrap']['body_mass_g'].mean())
b = (data[data['species'] == 'Adelie']['body_mass_g'].mean())
c = (data[data['species'] == 'Gentoo']['body_mass_g'].mean())
data1 = [[a, 'ChinStrap'], [b, 'Adelie'], [c, 'Gentoo']]
df = pd.DataFrame(data1, columns=['body_mass', 'species'])
df.boxplot(grid='false', color='blue', fontsize=10, rot=30)

# wykres pudelkowy zaleznosci wagi pingwina od gatunku i plci
(data.groupby(by=['sex', 'species'])['body_mass_g'].mean())
plt.show()
