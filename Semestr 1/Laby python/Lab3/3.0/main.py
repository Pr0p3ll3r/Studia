suma = 0
parzystych = 0

pobrana = 1
while pobrana != 0:
    pobrana = int(input("Podaj liczbe: "))

    if pobrana % 2 == 0 and pobrana > 10:
        suma += pobrana
        parzystych += 1

print("Liczb parzystych: " + str(parzystych))
print("Suma liczb parzystych: " + str(suma))