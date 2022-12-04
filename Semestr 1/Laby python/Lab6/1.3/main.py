print("Program który pobiera od użytkownika liczby do wystąpienia liczby będącej wielokrotnością liczby 10,"
      " a następnie wyświetla najmniejszy element oraz średnią wczytanych liczb.")

suma = 0
liczba = int(input("Podaj liczbę: "))
min = liczba
i = 1
while liczba % 10 != 0:
    liczba = int(input("Podaj liczbę: "))
    i += 1
    suma += liczba
    if liczba < min:
        min = liczba

print("Najmniejsza z podanych liczb to", min)
print("Srednia wczytanych liczb wynosi", suma/i)
