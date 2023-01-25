import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

data = pd.read_csv("wdbc.csv", sep=',', header=None)
mask = data[data.columns[1]].values == 'B'
data[data.columns[1]][mask] = 1
data[data.columns[1]][~mask] = 0
x = data.values[:,1:].astype(float)
y = data.values[:,0].astype(int)
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.2,
                                random_state=221, shuffle=True)
scaler = StandardScaler()
x_train = scaler.fit_transform(x_train)
x_test = scaler.transform(x_test)

outliers = np.abs((x_train - x_train.mean())/x_train.std())>3
x_train_no_outliers = x_train[~outliers]
x_train_mean = x_train.copy()
x_train_mean[outliers] = x_train.mean()

from keras.models import Sequential
from keras.layers import Dense
from keras.optimizers import Adam

class_num = 1
input_s = x_train_mean.shape[1]
learning_rate = 0.0001

model1 = Sequential()
model1.add(Dense(32, activation="relu", input_shape=(input_s,)))
model1.add(Dense(64, activation="relu"))
model1.add(Dense(32, activation="relu"))
model1.add(Dense(class_num, activation = 'softmax'))

model2 = Sequential()
model2.add(Dense(64, activation="relu", input_shape=(input_s,)))
model2.add(Dense(128, activation="relu"))
model2.add(Dense(64, activation="relu"))
model2.add(Dense(class_num, activation = 'softmax'))

model3 = Sequential()
model3.add(Dense(units=128, activation="relu", input_shape=(input_s,)))
model3.add(Dense(units=256, activation="relu"))
model3.add(Dense(units=128, activation="relu"))
model3.add(Dense(class_num, activation = 'softmax'))

model1.compile(optimizer=Adam(learning_rate),
    loss='categorical_crossentropy',
    metrics=['acc'])

model2.compile(optimizer=Adam(learning_rate),
    loss='categorical_crossentropy',
    metrics=['acc'])

model3.compile(optimizer=Adam(learning_rate),
    loss='categorical_crossentropy',
    metrics=['acc'])

epochsCount = 20

model1.fit(x_train_mean, y_train, batch_size=64, epochs=epochsCount, verbose=2)
model2.fit(x_train_mean, y_train, batch_size=64, epochs=epochsCount, verbose=2)
model3.fit(x_train_mean, y_train, batch_size=64, epochs=epochsCount, verbose=2)

from sklearn.model_selection import KFold
from sklearn.metrics import accuracy_score

scores1 = []
scores2 = []
scores3 = []
scaler = StandardScaler()
for train_index, test_index in KFold(5).split(x_train):
  x_train_cv = x_train[train_index]
  x_test_cv = x_train[test_index]
  y_train_cv = y_train[train_index]
  y_test_cv = y_train[test_index]
  x_train_cv = scaler.fit_transform(x_train_cv)
  x_test_cv = scaler.transform(x_test_cv)
  model1.fit(x_train_cv, y_train_cv, batch_size=64,
      epochs=epochsCount, verbose=2)
  y_pred = model1.predict(x_test_cv).argmax(axis=1)
  y_test_cv = y_test_cv.argmax(axis=0)
  scores1.append(accuracy_score(y_test_cv, y_pred))
  x_train_cv = x_train[train_index]
  x_test_cv = x_train[test_index]
  y_train_cv = y_train[train_index]
  y_test_cv = y_train[test_index]
  x_train_cv = scaler.fit_transform(x_train_cv)
  x_test_cv = scaler.transform(x_test_cv)
  model2.fit(x_train_cv, y_train_cv, batch_size=64,
      epochs=epochsCount, verbose=2)
  y_pred = model2.predict(x_test_cv).argmax(axis=1)
  y_test_cv = y_test_cv.argmax(axis=0)
  scores2.append(accuracy_score(y_test_cv, y_pred))

  x_train_cv = x_train[train_index]
  x_test_cv = x_train[test_index]
  y_train_cv = y_train[train_index]
  y_test_cv = y_train[test_index]
  x_train_cv = scaler.fit_transform(x_train_cv)
  x_test_cv = scaler.transform(x_test_cv)
  model3.fit(x_train_cv, y_train_cv, batch_size=64,
      epochs=epochsCount, verbose=2)
  y_pred = model3.predict(x_test_cv).argmax(axis=1)
  y_test_cv = y_test_cv.argmax(axis=0)
  scores3.append(accuracy_score(y_test_cv, y_pred))

print(f"Dokładności dla poszczególnych foldów: {scores1}")
print(f"Średnia dokładność: {np.mean(scores1):.2f} +/- {np.std(scores1):.2f}")
print(f"Dokładności dla poszczególnych foldów: {scores2}")
print(f"Średnia dokładność: {np.mean(scores2):.2f} +/- {np.std(scores2):.2f}")
print(f"Dokładności dla poszczególnych foldów: {scores3}")
print(f"Średnia dokładność: {np.mean(scores3):.2f} +/- {np.std(scores3):.2f}")