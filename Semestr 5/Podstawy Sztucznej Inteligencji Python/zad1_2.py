import pandas as pd

data_csv = pd.read_csv("practice_lab_1.csv", sep=';')

nazwy_kolumn = list(data_csv.columns)
wartosci_kolumn = data_csv.values
pierwsza = wartosci_kolumn[0::2,0:]
druga = wartosci_kolumn[1::2,0:]
roznica = pierwsza-druga

