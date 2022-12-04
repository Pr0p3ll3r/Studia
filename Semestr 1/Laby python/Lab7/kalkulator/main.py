def obsluz_mnozenie():
    liczba1 = int(input("Podaj pierwsza liczbe: "))
    liczba2 = int(input("Podaj pierwsza liczbe: "))
    wynik = liczba1*liczba2
    print("Wynik operacji wynosi: " + str(wynik))

def obsluz_dzielenie():
    liczba1 = int(input("Podaj pierwsza liczbe: "))
    liczba2 = int(input("Podaj pierwsza liczbe: "))

    if liczba2 != 0:
        wynik = liczba1/liczba2
        print("Wynik operacji wynosi: " + str(wynik))
    else:
        print("Dzielenie przez zero!")

def obsluz_potegowanie():
    podstawa = -1
    wykladnik = -1
    while podstawa < 0 or wykladnik < 0:
        podstawa = int(input("Podaj podstawe potegowania: "))
        wykladnik = int(input("Podaj wykladnik: "))
    rezultat = podnies_do_potegi(podstawa, wykladnik)
    print("Wynik operacji wynosi: " + str(rezultat))

def podnies_do_potegi(podstawa, wykladnik):
    wynik = 1
    i = 0
    while i < wykladnik:
        wynik *= podstawa
        i+=1
    return wynik

print("Witaj w kalkulatorze")
wybor = 1
while wybor != 0:
    print("Wybierz operacje (0 - wyjscie, 1 - mnozenie, 2 - dzielenie, 3 - potegowanie)")
    wybor = int(input())
    if wybor == 1:
        obsluz_mnozenie()
    elif wybor == 2:
        obsluz_dzielenie()
    elif wybor == 3:
        obsluz_potegowanie()

