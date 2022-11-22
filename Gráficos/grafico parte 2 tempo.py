import matplotlib.pyplot as plt

plt.xlabel('Tamanho da entrada')
plt.ylabel('Tempo de processamento')
plt.title('Gráfico de tempo de processamento')
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.07591,0.24372,0.54241,2.145,5.31055,20.812,51.7541], label='Seleção', linewidth=3)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.066747,0.531358,2.84661,8.76634,36.3437,103.597,431.862], label='Mergesort', linewidth=3)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.073816,0.244975,0.611622,2.3025,6.35934,23.4565,63.5612],label='Heapsort', linewidth=3)

plt.legend()

plt.show()