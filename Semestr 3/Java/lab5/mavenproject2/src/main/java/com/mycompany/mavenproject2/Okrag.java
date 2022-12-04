package com.mycompany.mavenproject2;

public class Okrag extends Elipsa {
    int r;

    public Okrag(int r, int a, int b, int F1x, int F1y, float c) {
        super(a, b, F1x, F1y, c);
        this.r = r;
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
        super.obwod = (int) (2 * Math.PI * r);
    }
    
    protected void obliczPole()
    {
        super.pole = (int) (Math.PI * r * r);
    }
}
