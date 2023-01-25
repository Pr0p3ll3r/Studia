"""
Created on Fri Nov  4 18:00:03 2022

@author: student
"""

from sklearn.datasets import load_digits
import pandas as pd
import numpy as np
from sklearn.neighbors import KNeighborsClassifier as kNN
from sklearn.svm import SVC as SVM
from sklearn.metrics import confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier as DT

X, y = load_digits(return_X_y=True)
models = [kNN(), SVM()]
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state=221, shuffle=False)
for model in models:
    model.fit(X_train,y_train)
    y_pred = model.predict(X_test)
    print(confusion_matrix(y_test, y_pred))

model = DT(max_depth=20)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
cm = confusion_matrix(y_test, y_pred)
print(model)
print(cm)
print(np.diag(cm).sum()/cm.sum())

from sklearn.preprocessing import StandardScaler
from matplotlib import pyplot as plt
from sklearn.decomposition import PCA
def qualitative_to_0_1(data,column,value_to_be_1):
    mask=data[column].values==value_to_be_1
    data[column][mask]=1
    data[column][~mask]=0
    return data

data=pd.read_csv("voice_extracted_features.csv",sep=',')
data=qualitative_to_0_1(data,'label','female')
vals=data.values.astype(np.float)
X, y=vals[:,:-1], vals[:,-1]
X_train,X_test, y_train, y_test=train_test_split(X,y,test_size=0.2, shuffle=False)
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)

pca = PCA()
pca.fit(X_train)
variances = pca.explained_variance_ratio_
cumulated_variances = variances.cumsum()
plt.scatter(np.arange(variances.shape[0]), cumulated_variances)
plt.yticks(np.arange(0, 1.1, 0.1))
PC_num = (cumulated_variances<0.95).sum() + 1

for model in models:
    model.fit(X_train,y_train)
    y_pred = model.predict(X_test)
    print(confusion_matrix(y_test, y_pred))

model = DT(max_depth=20)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
cm = confusion_matrix(y_test, y_pred)
print(model)
print(cm)
print(np.diag(cm).sum()/cm.sum())

pca = PCA(PC_num)
pca.fit(X_train)
X_train = pca.transform(X_train)
X_test = pca.transform(X_test)
cumulated_variances = variances.cumsum()
plt.scatter(np.arange(variances.shape[0]), cumulated_variances)
plt.yticks(np.arange(0, 1.1, 0.1))
PC_num = (cumulated_variances<0.95).sum() + 1

for model in models:
    model.fit(X_train,y_train)
    y_pred = model.predict(X_test)
    print(confusion_matrix(y_test, y_pred))

model = DT(max_depth=20)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
cm = confusion_matrix(y_test, y_pred)
print(model)
print(cm)
print(np.diag(cm).sum()/cm.sum())

from sklearn.datasets import load_digits
from sklearn.decomposition import FastICA

X_train,X_test, y_train, y_test=train_test_split(X,y,test_size=0.2, shuffle=False)
ica = FastICA(n_components=7)
ica.fit(X_train)
X_train = ica.transform(X_train)
X_test = ica.transform(X_test)
X_transformed = ica.fit_transform(X)
for model in models:
    model.fit(X_train,y_train)
    y_pred = model.predict(X_test)
    print(confusion_matrix(y_test, y_pred))

model = DT(max_depth=20)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
cm = confusion_matrix(y_test, y_pred)
print(model)
print(cm)
print(np.diag(cm).sum()/cm.sum())