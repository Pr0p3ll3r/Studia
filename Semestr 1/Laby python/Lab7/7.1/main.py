def dodanie_oceny(tab = []):
    ocena = (int(input("Podaj ocene(2-5): ")))
    if ocena < 2 or ocena > 5:
        print("Bład")
    else:
        tab.append(ocena)

def zaliczenie(tab = []):
    zaliczenie = 1
    for i in range(0, len(tab)):
        if tab[i] == 2:
            zaliczenie = 0
            break
    if zaliczenie == 1:
        print("Semestr zaliczony")
    else:
        print("Semestr niezaliczony")

def oblicz_srednia(dlugosc, tab = []):
    suma = 0
    for i in range(0, dlugosc):
        suma += tab[i]
    return suma/dlugosc

def sortowanie(srednia, tab = []):
    posortowana = []
    for i in range(0, len(tab)):
        if tab[i] < srednia:
            posortowana.insert(0, tab[i])
        else:
            posortowana.insert(-1, tab[i])
    return posortowana
def wyswietlenie(tab = []):
    print(tab)

print("Witaj tutaj sprawdzisz swoje oceny")
wybor = 1
tab = []
while wybor != 0:
    print("Wybierz operacje (0 - wyjscie, 1 - dodanie oceny, 2 - sprawdz zaliczenie, 3 - srednia, 4 - sortowanie ocen, 5 - wyswietlenie ocen)")
    wybor = int(input())
    if wybor == 1:
        dodanie_oceny(tab)
    elif wybor == 2:
        zaliczenie(tab)
    elif wybor == 3:
        print("Srednia wynosi: " + str(oblicz_srednia(len(tab), tab)))
    elif wybor == 4:
        tab = sortowanie(oblicz_srednia(len(tab), tab), tab)
    elif wybor == 5:
        wyswietlenie(tab)

