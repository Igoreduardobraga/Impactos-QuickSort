import matplotlib.pyplot as plt

plt.xlabel('Tamanho da entrada')
plt.ylabel('Número de comparações')
plt.title('Gráfico de comparações')
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[1001.2,
5002.4,
1001.2,
50002.9,
100000,
500001,
1000001.6], label='Seleção', linewidth=2)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[982.1,
4987.6,
9992.4,
49989.3,
99985.8,
499983.1,
999978], label='Mergesort', linewidth=2)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[11711.5,
75590.2,
166337.6,
1006327.1,
2162419.8,
12561316.7,
26618641.9],label='Heapsort', linewidth=2)

plt.legend()

plt.show()