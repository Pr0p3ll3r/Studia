podstawa = int(input("Podaj podstawe potęgi (dodatnia)"))
wykladnik = int(input("Podaj wykladnik potęgi (dodatnia)"))
ogranicznik = int(input("Podaj ogranicznik (dodatnia)"))

if podstawa <= 0 or wykladnik <= 0 or ogranicznik <= 0:
    print("Błędne dane")
    exit(0)

wynik = podstawa
i = 0
while i < wykladnik:
    wynik *= podstawa
    if wynik >= ogranicznik:
        break
    i += 1

print(i)

wynik = podstawa
while i != 0:
    wynik *= podstawa
    i -= 1

print("Wynik: ", wynik)
