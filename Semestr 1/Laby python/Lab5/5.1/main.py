print("liczba ujemna - kończy program, 0 - początek/koniec liczenia średniej")
liczba = int(input("Podaj liczbę :"))
x = 0
suma = 0
while liczba >= 0:
    liczba = int(input("Podaj liczbę :"))
    if liczba == 0:
        liczba = int(input("Podaj liczbę do sredniej:"))
        suma += liczba
        x += 1
        while liczba != 0:
            liczba = int(input("Podaj liczbę do sredniej:"))
            if liczba > 0:
                suma += liczba
                x += 1

print("Srednia wynosi: ", str(suma/x))