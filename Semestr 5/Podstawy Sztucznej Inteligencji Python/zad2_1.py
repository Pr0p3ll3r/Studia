# -*- coding: utf-8 -*-
"""
Created on Fri Oct 21 18:28:38 2022

@author: student
"""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error, mean_squared_error, mean_absolute_percentage_error

bh_data = pd.read_csv('practice_lab_2.csv', sep=';')
bh_cechy = bh_data.columns.to_list()
bh_arr = bh_data.values
X, y = bh_arr[:,:-1], bh_arr[:,-1]
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2, random_state= 221, shuffle=False)

linReg = LinearRegression()
linReg.fit(X_train, y_train)
y_pred = linReg.predict(X_test)
minval = min(y_test.min(), y_pred.min())
maxval = max(y_test.max(), y_pred.max())
plt.scatter(y_test, y_pred)
plt.plot([minval, maxval], [minval, maxval])
plt.xlabel('y_test')
plt.ylabel('y_pred')

X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state= 221, shuffle=True)
linReg = LinearRegression()
linReg.fit(X_train, y_train)
y_pred = linReg.predict(X_test)
mse = mean_squared_error(y_test, y_pred)
mae = mean_absolute_error(y_test, y_pred)
mape = mean_absolute_percentage_error (y_test, y_pred)

outliers = np.abs((y_train - y_train.mean())/y_train.std())>2.5
X_train_no_outliers = X_train[~outliers,:]
y_train_no_outliers = y_train[~outliers]
y_train_mean = y_train.copy()
y_train_mean[outliers] = y_train.mean()

linReg = LinearRegression()
linReg.fit(X_train_no_outliers, y_train_no_outliers)
y_pred = linReg.predict(X_test)
mse_no = mean_squared_error(y_test, y_pred)
mae_no = mean_absolute_error(y_test, y_pred)
mape_no = mean_absolute_percentage_error (y_test, y_pred)

linReg = LinearRegression()
linReg.fit(X_train, y_train_mean)
y_pred = linReg.predict(X_test)
mse_mean = mean_squared_error(y_test, y_pred)
mae_mean = mean_absolute_error(y_test, y_pred)
mape_mean = mean_absolute_percentage_error (y_test, y_pred)

linReg = LinearRegression()
linReg.fit(X_train, y_train_mean)
bh_cechy = bh_data.columns.to_list()
niezleżne_cechy = bh_cechy[:-1]
fig, ax = plt.subplots(1,1)
x = np.arange(len(niezleżne_cechy))
wagi = linReg.coef_
ax.bar(x, wagi)
ax.set_xticks(x)
ax.set_xticklabels(niezleżne_cechy, rotation = 90)