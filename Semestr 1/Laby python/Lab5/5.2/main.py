n = int(input("Podaj rozmiar tablicy: "))
tablica = [0]*n
i = 0
while i < n:
    tablica[i] = int(input("Podaj element tablicy: "))
    i += 1
ostatni = tablica.pop(n-1)
suma = 0
i = 0
while i < n-1:
    if tablica[i] > ostatni:
        suma += tablica[i]
    i += 1
print("Suma wynosi: ", suma)
print("Srednia wynosi: ", suma/i)
