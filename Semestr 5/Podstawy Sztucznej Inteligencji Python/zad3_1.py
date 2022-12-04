# -*- coding: utf-8 -*-
"""
Created on Fri Oct 28 18:03:58 2022

@author: student
"""

import pandas as pd
import numpy as np
from sklearn.neighbors import KNeighborsClassifier as kNN
from sklearn.svm import SVC as SVM
from sklearn.metrics import confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier as DT
from sklearn.preprocessing import StandardScaler
from sklearn.tree import plot_tree
from matplotlib import pyplot as plt

data = pd.read_csv('practice_lab_3.csv', sep=';')
mask = data ['Gender'].values == 'Female'
data['Gender'][mask] = 1
data['Gender'][~mask] = 0

mask = data ['Married'].values == 'Yes'
data['Married'][mask] = 1
data['Married'][~mask] = 0

mask = data ['Education'].values == 'Graduate'
data['Education'][mask] = 1
data['Education'][~mask] = 0

mask = data ['Self_Employed'].values == 'Yes'
data['Self_Employed'][mask] = 1
data['Self_Employed'][~mask] = 0

mask = data ['Loan_Status'].values == 'Y'
data['Loan_Status'][mask] = 1
data['Loan_Status'][~mask] = 0

cat_feature = pd.Categorical(data.Property_Area)
one_hot = pd.get_dummies(cat_feature)
data = pd.concat([data, one_hot], axis = 1)
data = data.drop(columns = ['Property_Area'])
    
y = data['Loan_Status'].values.astype(np.int32)
X = data.drop(columns = ['Loan_Status']).values.astype(np.float64)

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
print(cm)
plt.figure(figsize=(20,10))
tree_vis = plot_tree(model,feature_names=
                     data.columns[:-1].to_list(),
                     class_names=['N', 'Y'], fontsize = 15)

scaler = StandardScaler()
scaler.fit(X_train)
X_train = scaler.transform(X_train)
X_test = scaler.transform(X_test)
for model in models:
    model.fit(X_train,y_train)
    y_pred = model.predict(X_test)
    print(confusion_matrix(y_test, y_pred))
    
model = DT(max_depth=20)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
cm = confusion_matrix(y_test, y_pred)
print(cm)
plt.figure(figsize=(20,10))
tree_vis = plot_tree(model,feature_names=
                     data.columns[:-1].to_list(),
                     class_names=['N', 'Y'], fontsize = 15)