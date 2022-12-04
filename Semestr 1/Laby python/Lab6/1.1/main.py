print("Program który pobiera 4 liczby dodatnie i 3 pierwsze dzieli przez ostatnia")

a, b, c, d = 0, 0, 0, 0

while a <= 0:
    a = int(input("Wprowadź dodatnią liczbę: "))

while b <= 0:
    b = int(input("Wprowadź dodatnią liczbę: "))

while c <= 0:
    c = int(input("Wprowadź dodatnią liczbę: "))

while d <= 0:
    d = int(input("Wprowadź dodatnią liczbę: "))

print("Wynik dzielenia", a, "przez", d, "równa się", a/d)
print("Wynik dzielenia", b, "przez", d, "równa się", b/d)
print("Wynik dzielenia", c, "przez", d, "równa się", c/d)
