print("Program który pobiera n liczb, a następnie wyświetla sumę ich kwadratów")

suma = 0

n = int(input("Ile liczb chcesz wczytać?\n"))

while n < 0:
    n = int(input("Ile liczb chcesz wczytać?\n"))

for n in range(0, n):
    liczba = int(input("Podaj liczbę:"))
    suma += liczba * liczba

print("Suma kwadratow podanych liczb wynosi", suma)
