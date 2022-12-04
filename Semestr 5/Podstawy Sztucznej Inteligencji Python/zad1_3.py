import numpy as np
import matplotlib.pyplot as plt
import math

fig, ax = plt.subplots(2, 3, figsize=(10, 10))

x = np.arange(-5, 5, 0.01)
x = np.append(x, 5)
y = np.tanh(x)
ax[0, 0].plot(x, y)

y2 = []
for i in range(0, len(x)):
    y2.append((math.exp(x[i])-math.exp(-x[i]))/(math.exp(x[i])+math.exp(-x[i])))
ax[0, 1].plot(x, y2)

y3 = []
for i in range(0, len(x)):
    y3.append(1/(1+math.exp(-x[i])))
ax[0, 2].plot(x, y3)

y4 = []
for i in range(0, len(x)):
    if x[i] <= 0:
        y4.append(0)
    else:
        y4.append(x[i])

ax[1, 0].plot(x, y4)

y5 = []
for i in range(0, len(x)):
    if x[i] <= 0:
        y5.append(math.exp(x[i])-1)
    else:
        y5.append(x[i])

ax[1, 1].plot(x, y5)

plt.show()
