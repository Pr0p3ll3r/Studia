print("Program który n liczb, a następnie wyświetlić największą i najmniejszą z nich")

n = int(input("Ile liczb chcesz wczytać?\n"))

while n <= 0:
    n = int(input("Ile liczb chcesz wczytać?\n"))

liczba = int(input("Podaj liczbę: "))
min = liczba
max = liczba
i = 1

while i < n:
    liczba = int(input("Podaj liczbę: "))
    if liczba < min:
        min = liczba
    if liczba > max:
        max = liczba
    i += 1

print("Największa z liczb to", max, "\nNajmniejsza z liczb to", min)
