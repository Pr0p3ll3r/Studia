print("Program który wczytuje tablicę n liczb. Znajduje trzy kolejne liczby w tablicy, których suma jest największa."
      "Wyświeta numer indeksu początkowego znalezionych liczb.")

n = int(input("Ile liczb chcesz wczytać? (min. 3)\n"))
tablica = [0]*n
max = 0
index = 0
while n < 3:
    n = int(input("Ile liczb chcesz wczytać? (min. 3)\n"))
    tablica = [0] * n

for i in range(0, n):
    tablica[i] = int(input("Podaj liczbę: "))

max = tablica[0] + tablica[1] + tablica[2]

for n in range(1, n-2):
    suma = tablica[n] + tablica[n+1] + tablica[n+2]
    if suma > max:
        max = suma
        index = n

print("Numer indeksu początkowego znalezionych liczb to", index)
