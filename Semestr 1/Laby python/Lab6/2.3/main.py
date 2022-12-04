print("Program ktory wczytuje od użytkownika podaną ilość liczb "
      "(w przypadku podania wartości mniejszej od dwóch lub nieparzystej, kończy działanie)."
      "Wyświetla średnią dwóch liczb znajdujących się pośrodku wczytanego zbioru")

n = int(input("Ile liczb chcesz wczytać?\n"))

if n < 2 or n % 2 != 0:
    exit(0)

tablica = [0]*n

for i in range(0, n):
    tablica[i] = int(input("Podaj liczbę: "))

suma = tablica[int(n/2-1)] + tablica[int(n/2)]

print("Średnia dwóch liczb znajdujących się pośrodku wczytanego zbioru wynosi:", suma/2)
