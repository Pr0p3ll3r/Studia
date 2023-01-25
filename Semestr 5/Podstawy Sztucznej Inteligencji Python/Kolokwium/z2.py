import pandas as pd
import numpy as np
data = pd.read_csv("Pizza R.csv", sep = ',')
mask = data ['brand'].values == 'A'
data['brand'][mask] = 1
data['brand'][~mask] = 0
x = data.drop(columns = 'brand')
y = data['brand'].astype(int)

from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.2,random_state=221, shuffle=True)

from sklearn.decomposition import PCA
pca = PCA()
pca.fit(x_train)
 
variances = pca.explained_variance_ratio_
cumulated_variances = variances.cumsum()
 
PC_num95 = (cumulated_variances<0.95).sum() + 1
PC_num80 = (cumulated_variances<0.80).sum() + 1

from sklearn.decomposition import FastICA
from sklearn.neighbors import KNeighborsClassifier as kNN
from sklearn.metrics import accuracy_score, confusion_matrix

pca_transform = PCA(PC_num95)
x_train_reduced95 = pca_transform.fit_transform(x_train)
x_test_reduced95 = pca_transform.transform(x_test)
ica_transformer = FastICA(PC_num95)
x_train_reduced95 = ica_transformer.fit_transform(x_train_reduced95)
x_test_reduced95 = ica_transformer.transform(x_test_reduced95)

pca_transform = PCA(PC_num80)
x_train_reduced80 = pca_transform.fit_transform(x_train)
x_test_reduced80 = pca_transform.transform(x_test)
ica_transformer = FastICA(PC_num80)
x_train_reduced80 = ica_transformer.fit_transform(x_train_reduced80)
x_test_reduced80 = ica_transformer.transform(x_test_reduced80)

model = kNN(6, weights = 'distance')
model.fit(x_train, y_train)
y_pred = model.predict(x_test)
print("Klasyfikacja oryginalnych danych za pomocą kNN z liczbą sąsiadów 6")
print(f'Dokładność: {accuracy_score(y_test, y_pred)}')
print(confusion_matrix(y_test, y_pred))

model = kNN(17, weights = 'distance')
model.fit(x_train, y_train)
y_pred = model.predict(x_test)
print("Klasyfikacja oryginalnych danych za pomocą kNN z liczbą sąsiadów 17")
print(f'Dokładność: {accuracy_score(y_test, y_pred)}')
print(confusion_matrix(y_test, y_pred))

model = kNN(30, weights = 'distance')
model.fit(x_train, y_train)
y_pred = model.predict(x_test)
print("Klasyfikacja oryginalnych danych za pomocą kNN z liczbą sąsiadów 30")
print(f'Dokładność: {accuracy_score(y_test, y_pred)}')
print(confusion_matrix(y_test, y_pred))
print();

print("Wariancja 80%")
model = kNN(6, weights = 'distance')
model.fit(x_train_reduced80, y_train)
y_pred = model.predict(x_test_reduced80)
print("Klasyfikacja zredukowanych danych za pomocą kNN z liczbą sąsiadów 6")
print(f'Dokładność: {accuracy_score(y_test, y_pred)}')
print(confusion_matrix(y_test, y_pred))

model = kNN(17, weights = 'distance')
model.fit(x_train_reduced80, y_train)
y_pred = model.predict(x_test_reduced80)
print("Klasyfikacja zredukowanych danych za pomocą kNN z liczbą sąsiadów 17")
print(f'Dokładność: {accuracy_score(y_test, y_pred)}')
print(confusion_matrix(y_test, y_pred))

model = kNN(30, weights = 'distance')
model.fit(x_train_reduced80, y_train)
y_pred = model.predict(x_test_reduced80)
print("Klasyfikacja zredukowanych danych za pomocą kNN z liczbą sąsiadów 30")
print(f'Dokładność: {accuracy_score(y_test, y_pred)}')
print(confusion_matrix(y_test, y_pred))
print();

print("Wariancja 95%")
model = kNN(6, weights = 'distance')
model.fit(x_train_reduced95, y_train)
y_pred = model.predict(x_test_reduced95)
print("Klasyfikacja zredukowanych danych za pomocą kNN z liczbą sąsiadów 6")
print(f'Dokładność: {accuracy_score(y_test, y_pred)}')
print(confusion_matrix(y_test, y_pred))

model = kNN(17, weights = 'distance')
model.fit(x_train_reduced95, y_train)
y_pred = model.predict(x_test_reduced95)
print("Klasyfikacja zredukowanych danych za pomocą kNN z liczbą sąsiadów 17")
print(f'Dokładność: {accuracy_score(y_test, y_pred)}')
print(confusion_matrix(y_test, y_pred))

model = kNN(30, weights = 'distance')
model.fit(x_train_reduced95, y_train)
y_pred = model.predict(x_test_reduced95)
print("Klasyfikacja zredukowanych danych za pomocą kNN z liczbą sąsiadów 30")
print(f'Dokładność: {accuracy_score(y_test, y_pred)}')
print(confusion_matrix(y_test, y_pred))