n = int(input('podaj ilosc elementow do wpisania '))
tablica = []
while n > 0:
    tablica.append(int(input('podaj liczbe do dodania ')))
    n -= 1

print('twoja tablica to: {}'.format(tablica))
print('dwa najwieksze elementy to {} i {}'
      .format(tablica.pop(tablica.index(max(tablica))), max(tablica)))

# print('twoja tablica to: {}, dwa najwieksze elementy to {} i {}'.format(tablica, tablica.pop(tablica.index(max(tablica))), max(tablica)))