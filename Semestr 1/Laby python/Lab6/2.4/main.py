print("Program ktory pobiera od użytkownika n liczb całkowitych (od 1 do 100)"
      "Sprawdza, czy w podanej tablicy istnieje choć jedna para takich samych liczb.")

n = int(input("Ile liczb chcesz wczytać?(min. 2)\n"))

while n < 2:
    n = int(input("Ile liczb chcesz wczytać?(min. 2)\n"))

tablica = [0] * n

for i in range(0, n):
    tablica[i] = int(input("Podaj liczbę: "))

for j in range(0, n-1):
    for k in range(j+1, n):
        if tablica[j] == tablica[k]:
            print("W podanej tablicy istnieje przynajmniej jedna para takich samych liczb")
            exit(0)

print("W podanej tablicy nie istnieje para takich samych liczb")