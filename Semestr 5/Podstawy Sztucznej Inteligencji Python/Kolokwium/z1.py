from sklearn.datasets import load_diabetes
import matplotlib.pyplot as plt
import pandas as pd

data = load_diabetes()
x = data.data
y = data.target

df = pd.DataFrame(data.data, columns=data.feature_names)
df = df[["sex", "age", "s1", "s2", "s3"]]

df['target'] = y
corr_matrix = df.corr()['target']

plt.bar(corr_matrix.index, corr_matrix.values)
plt.xlabel("Kolumna")
plt.ylabel("Wartosc korelacji")
plt.title("Koleracja wybranych kolumn z kolumną wynikową")
plt.show()