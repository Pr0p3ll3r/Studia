print('Podaj liczby 0-999')

blad=True

while blad:
    liczba = int(input(''))
    if liczba < 0 or liczba > 999:
        print('Podaj poprawna liczbe')
    else: blad=False

jednosci = liczba%10
dziesiatki = int(liczba/10)%10
setki = int(liczba/100)

suma_cyfr = jednosci + dziesiatki + setki

print('Suma cyfr: ' + str(suma_cyfr) + ', setki: ' + str(setki) + ', dziesiątki: ' + str(dziesiatki) + ', jedności: ' + str(jednosci))

