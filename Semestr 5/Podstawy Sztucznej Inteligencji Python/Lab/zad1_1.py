import numpy as np
import matplotlib.pyplot as plt

arr = np.array([[2,3,5,1],
 [5,1,2,8],
 [5,1,6,-1]])
pojedynczy_element = arr[0,3]
pojedynczy_element_od_konca = arr[-3,-1]
print(pojedynczy_element)

x = np.arange(0, 10, 0.2)
y = np.tan(x**2 - 5*x + 3)
plt.scatter(x, y)
plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('y')
fig, ax = plt.subplots(1, 2, figsize = (10, 5))
ax[0].plot(x, y)
ax[0].set_xlabel("x")
ax[0].set_ylabel("y")
ax[1].scatter(x, y)
ax[1].set_xlabel("x")
ax[1].set_ylabel("y")
fig.tight_layout()
fig, ax = plt.subplots(2,2, figsize = (10, 10))
ax[0,0].scatter(x,y)
ax[0,1].plot(x,y)
ax[1,0].hist(y)
ax[1,1].boxplot(y)