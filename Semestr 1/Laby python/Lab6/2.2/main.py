print("Program ktory podnosi liczbe do potegi")

liczba = int(input("Podaj podstawę potęgi: "))
while liczba < 0:
    liczba = int(input("Podaj podstawę potęgi: "))

wykladnik = int(input("Podaj wykładnik potęgi: "))
while wykladnik < 0:
    wykladnik = int(input("Podaj wykładnik potęgi: "))

if liczba == 0:
    wynik = 0
elif wykladnik == 0:
    wynik = 1
else:
    wynik = liczba
    for i in range(1, wykladnik):
        wynik *= liczba

print("Wynik potęgowania:", wynik)
