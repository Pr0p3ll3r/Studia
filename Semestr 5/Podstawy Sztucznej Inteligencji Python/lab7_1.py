# -*- coding: utf-8 -*-
"""
Created on Fri Dec  9 18:03:07 2022

@author: student
"""

from keras.layers import Conv2D, Flatten, Dense, MaxPooling2D
from keras.models import Sequential
from tensorflow.keras.optimizers import Adam
from keras.datasets import mnist
from sklearn.metrics import confusion_matrix
import numpy as np

train, test = mnist.load_data()

X_train, y_train = train[0], train[1]
X_test, y_test = test[0], test[1]

el = X_train[0]
exp_res = y_train[0]
# wybór obserwacji
samples = 2000
X_train = X_train[:samples,:,:]
X_test = X_test[:samples,:,:]
y_train = y_train[:samples]
y_test = y_test[:samples]

X_train = np.expand_dims(X_train, axis=-1)
X_test = np.expand_dims(X_test, axis=-1)
class_cnt = np.unique(y_train).shape[0]
filter_cnt = 32
neuron_cnt = 32
learning_rate = 0.0001
act_func = 'relu'
kernel_size = (3,3)
pooling_size = (2,2)
conv_rule = 'same'
epochs_cnt = 25
model = Sequential()
model.add(Conv2D(input_shape = X_train.shape[1:],
        filters=filter_cnt,
        kernel_size = kernel_size,
        padding = conv_rule, activation = act_func))
model.add(MaxPooling2D(pooling_size))
model.add(Flatten())
model.add(Dense(class_cnt, activation='softmax'))
model.compile(optimizer=Adam(learning_rate),
              loss='SparseCategoricalCrossentropy',
              metrics=['accuracy'])
model.fit(x = X_train, y = y_train,
          epochs = epochs_cnt,
          validation_data=(X_test, y_test))

y_pred = model.predict(X_test).argmax(axis=1)
cm = confusion_matrix(y_test, y_pred)
print(cm)
