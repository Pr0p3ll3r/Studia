# -*- coding: utf-8 -*-
"""
deserialize json
"""
import json


class DeserializeJson:
    # konstruktor
    def __init__(self, filename):
        print("let's deserialize something")
        tempdata = open(filename, encoding="utf8")
        self.data = json.load(tempdata)

    # przykładowe statystyki
    def somestats(self):
        statystyki = {}
        for dep in self.data:
            urzad = dep['Województwo'].strip() + ' ' + dep['typ_JST']
            if urzad in statystyki:
                statystyki[urzad] += 1
            else:
                statystyki[urzad] = 1
        for urzad, ilosc in statystyki.items():
            wojewodztwo, urzad = urzad.split(' ')
            print(wojewodztwo + ' ' + urzad + ': ' + str(ilosc))
