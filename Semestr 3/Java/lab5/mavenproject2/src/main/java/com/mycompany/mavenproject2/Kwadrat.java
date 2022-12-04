package com.mycompany.mavenproject2;

public class Kwadrat extends Prostokat{
    
    public Kwadrat(int a) {
        this.a = a;
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
          
    @Override
    protected void obliczObwod()
    {
        super.obwod = a*4;
    }
    
    @Override
    protected void obliczPole()
    {
        super.pole = a * a;
    }
}
