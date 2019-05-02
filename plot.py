import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("datos.dat")
n_points = int(np.sqrt(len(data)))
grid = np.reshape(data, (201,201))

plt.figure(figsize=(15,5))
plt.subplot(1,2,1)
plt.imshow(grid)
plt.xlabel("X")
plt.ylabel("T")
plt.colorbar(label="Temperatura")

plt.subplot(1,2,2)
T1=data[0,:]
T2=data[-1,:]
x=np.arange(0,201,1)
plt.xlabel('Indice X')
plt.ylabel('Temperatura')
plt.plot(x,T1,label='Temperatura Inicial')
plt.plot(x,T2,label='Temperatura Final')
plt.legend()
plt.savefig("plot.png")