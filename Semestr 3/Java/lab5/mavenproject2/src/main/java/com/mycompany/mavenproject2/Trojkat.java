package com.mycompany.mavenproject2;

public class Trojkat extends Wielokat {
    int h;
    int a;

    public Trojkat(int h, int a, int liczbaWierzcholkow, int liczbaBokow, int sumaKatowWewnetrznych) {
        super(liczbaWierzcholkow, liczbaBokow, sumaKatowWewnetrznych);
        this.h = h;
        this.a = a;
    }

    @Override
    protected void oblicz() {
        super.oblicz(); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    protected void rysuj() {
        super.rysuj(); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    protected void usun() {
        super.usun(); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    protected void przesun() {
        super.przesun(); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    protected String podajParametry() {
        return super.podajParametry(); //To change body of generated methods, choose Tools | Templates.
    }
    
    protected void obliczObwod()
    {
        super.obwod = a*3;
    }
    
    protected void obliczPole()
    {
        super.pole = a * h * 1/2;
    }
}
