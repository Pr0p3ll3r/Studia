# -*- coding: utf-8 -*-
"""
Created on Fri Nov 18 00:42:41 2022

@author: Kuba
"""
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
dane = pd.read_csv("voice_extracted_features.csv", sep=",");
print (dane)
mask = dane['label'].values == 'female'
dane['label'][mask] = 1;
dane['label'][~mask] = 0;
vals = dane.values.astype(np.float64);
x = vals[:,:-1];
y = vals[:,-1];
x_train, y_train, x_test, y_test = train_test_split(x,y,test_size=0.2,shuffle=False)
