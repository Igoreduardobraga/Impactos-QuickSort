import matplotlib.pyplot as plt

plt.xlabel('Tamanho da entrada')
plt.ylabel('Tempo de processamento')
plt.title('Gráfico de tempo de processamento')
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.05493,0.2730,0.871168,3.051552,9.06314,30.1899,89.8293], label='Recursivo', linewidth=1)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.060344,0.27776,0.897763,3.06973,9.05245,30.2556,90.2694], label='Mediana K = 7', linewidth=1)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.07591,0.24372,0.54241,2.145,5.31055,20.812,51.7541],label='Seleção M = 10', linewidth=1)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.069159,
0.237421,
0.593545,
2.28774,
6.01479,
22.6348,
59.7612],label='Não Recursivo', linewidth=1)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.060938,
0.278593,
0.883127,
3.11903,
9.27047,
30.4318,
90.6661],label='Empilha Inteligente', linewidth=1)

plt.legend()

plt.show()