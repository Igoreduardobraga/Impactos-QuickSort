import matplotlib.pyplot as plt

plt.xlabel('Tamanho da entrada')
plt.ylabel('Tempo de processamento')
plt.title('Gráfico de tempo de processamento')
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.07591,0.24372,0.54241,2.145,5.31055,20.812,51.7541], label='M = 10', linewidth=2)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.064813,
0.226224,
0.542325,
2.14114,
5.32014,
20.9527,
51.8359], label='M = 100', linewidth=2)

plt.legend()

plt.show()