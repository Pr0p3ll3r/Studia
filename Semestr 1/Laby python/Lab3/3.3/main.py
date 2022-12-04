suma = 0
iloczyn = 0
i = 0

while suma < 255 and iloczyn < 50000:
    liczba = int(input("Podaj liczbę: \n"))
    suma += liczba
    if i == 0:
        iloczyn += liczba
    else:
        iloczyn *= liczba
    i += 1

print("Średnia arytmetyczna wynosi: " + str(suma/i))