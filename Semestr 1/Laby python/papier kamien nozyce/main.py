print('Gra "Papier, nożyce, kamień')

blad = True;

while blad:
    gracz1 = input('(gracz1) Co wybierasz (papier/nożyce/kamień):')

    if gracz1 == 'papier':
        gracz1wartosc = 0
        blad=False
    elif gracz1 == 'nożyce':
        gracz1wartosc = 1
        blad=False
    elif gracz1 == 'kamień':
        gracz1wartosc = 2
        blad=False
    else:
        print('Błąd')

blad = True;

while blad:
    gracz2 = input('(gracz2) Co wybierasz (papier/nożyce/kamień):')

    if gracz2 == 'papier':
        gracz2wartosc = 0
        blad=False
    elif gracz2 == 'nożyce':
        gracz2wartosc = 1
        blad=False
    elif gracz2 == 'kamień':
        gracz2wartosc = 2
        blad=False
    else:
        print('Błąd')


if gracz1wartosc == gracz2wartosc: print('Remis')
elif gracz1wartosc == 0 and gracz2wartosc == 2: print('Gracz 1 wygrywa')
elif gracz2wartosc == 0 and gracz1wartosc == 2: print('Gracz 2 wygrywa')
elif gracz1wartosc < gracz2wartosc: print('Gracz 2 wygrywa')
else: print('Gracz 1 wygrywa')
