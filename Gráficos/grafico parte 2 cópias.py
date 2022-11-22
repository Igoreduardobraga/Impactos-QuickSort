import matplotlib.pyplot as plt

plt.xlabel('Tamanho da entrada')
plt.ylabel('Número de cópias')
plt.title('Gráfico de cópias')
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[518.1,
2675.7,
3510.8,
27059.4,
66158.1,
360978.5,
179175.2], label='Seleção', linewidth=2)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[3018,
15022.3,
30031.7,
150035.2,
300031.4,
1500041.9,
3000038.2], label='Mergesort', linewidth=2)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[27309.3,
171213.6,
372624.2,
2212473,
4723899.4,
27072384.1,
57140385,],label='Heapsort', linewidth=2)

plt.legend()

plt.show()