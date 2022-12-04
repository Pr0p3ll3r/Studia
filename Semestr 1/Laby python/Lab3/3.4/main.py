min = 0
max = 0

pobrana = 1
i = 0
while pobrana != 0:
    liczba = int(input("Podaj liczbę: \n"))
    if i == 0:
        min = liczba

    if liczba % 2 != 0:
        pobrana = 0

    if liczba > max:
        max = liczba

    if liczba < min:
        min = liczba

    i += 1

podstawa = min
potega = max
while potega != 0:
    podstawa *= min
    potega -= 1

print("Najmniejsza: " + str(min))
print("Największa: " + str(max))
print("Potęga przy podstawie z liczby min i wykładniku z liczby max wynosi: " + str(podstawa))
