package com.mycompany.mavenproject2;

class Elipsa extends Figura{
    int a;
    int b;
    int F1x;
    int F1y;
    float c;

    public Elipsa(int a, int b, int F1x, int F1y, float c) {
        this.a = a;
        this.b = b;
        this.F1x = F1x;
        this.F1y = F1y;
        this.c = c;
    }  
    
    public int getA() {
        return a;
    }

    public int getB() {
        return b;
    }

    public int getF1x() {
        return F1x;
    }

    public int getF1y() {
        return F1y;
    }

    public float getC() {
        return c;
    }

    public void setA(int a) {
        this.a = a;
    }

    public void setB(int b) {
        this.b = b;
    }

    public void setF1x(int F1x) {
        this.F1x = F1x;
    }

    public void setF1y(int F1y) {
        this.F1y = F1y;
    }

    public void setC(int c) {
        this.c = c;
    }

    @Override
    protected String podajParametry() {
        return super.podajParametry(); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    protected void przesun() {
        super.przesun(); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    protected void usun() {
        super.usun(); //To change body of generated methods, choose Tools | Templates.
        
    }
    
    protected void oblicz(){
        c = (float) Math.sqrt(a*a - b*b);
    }
}
