n = int(input("Ile liczb wczytać? \n"))

i = 0
suma = 0
blad = True

while i < n:
    while blad:
        liczba = int(input("Podaj liczbę z przedziału od 10 do 50: \n"))
        if liczba >= 10 and liczba <= 50:
            blad = False
        else:
            print("Podaj poprawną liczbę")
    suma += liczba * liczba
    blad = True
    i += 1
print("Suma kwadratów podanych liczb wynosi: " + str(suma))
