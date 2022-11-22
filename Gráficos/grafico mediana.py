import matplotlib.pyplot as plt

plt.xlabel('Tamanho da entrada')
plt.ylabel('Tempo de processamento')
plt.title('Gráfico de tempo de processamento')
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.038084,0.278871,0.886289,3.05706,9.22808,30.5359,90.8127
], label='K = 3', linewidth=1)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.038125,0.258821,0.869231,3.03979,9.30457,30.7689,90.9018], label='K = 5', linewidth=1)
plt.plot([1000,5000,10000,50000,100000,500000,1000000],[0.060344,0.27776,0.897763,3.06973,9.05245,30.2556,90.2694],label='K = 7', linewidth=1)

plt.legend()

plt.show()