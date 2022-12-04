print("Program wczytujący liczby do momentu podania liczby zero."
      "Wyświetla sume liczb mniejszych od pierwszej podanej liczby")

suma = 0
liczba = int(input("Podaj liczbę: "))
pierwsza = liczba
while liczba != 0:
    liczba = int(input("Podaj liczbę: "))
    if liczba < pierwsza:
        suma += liczba

print("Suma wynosi ", suma)
