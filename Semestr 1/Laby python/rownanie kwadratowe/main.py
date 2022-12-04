from math import *

print('Podaj współczynniki równania')

a = int(input('Współczynnik a: '))
b = int(input('Współczynnik b: '))
c = int(input('Współczynnik c: '))

if a == 0:
    if b == 0:
        if c == 0:
            print('Nieskończenie wiele rozwiązań')
        else:
            print('Brak rozwiązań')
    else:
        print('1 rozwiązanie: ')
        print(str(-c / b))
else:
    d = b * b - 4 * a * c
    if d < 0:
        print('Brak rozwiązań')
    else:
        if d == 0:
            print('1 rozwiązanie: ')
            print(str(-b / 2 * a))
        else:
            print('2 rozwiązania: ')
            print(str((-b - sqrt(d)) / (2 * a)))
            print(str((-b + sqrt(d)) / (2 * a)))
