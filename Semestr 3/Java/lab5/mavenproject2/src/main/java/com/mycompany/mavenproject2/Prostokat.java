package com.mycompany.mavenproject2;

public class Prostokat extends Wielokat{
    int a;
    int b;

    public Prostokat(int a, int b, int liczbaWierzcholkow, int liczbaBokow, int sumaKatowWewnetrznych) {
        super(liczbaWierzcholkow, liczbaBokow, sumaKatowWewnetrznych);
        this.a = a;
        this.b = b;
    }
    
    @Override
    protected void oblicz() {
        super.oblicz(); //To change body of generated methods, choose Tools | Templates.
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
        super.obwod = a*2 + b*2;
    }
    
    protected void obliczPole()
    {
        super.pole = a * b;
    }
}
