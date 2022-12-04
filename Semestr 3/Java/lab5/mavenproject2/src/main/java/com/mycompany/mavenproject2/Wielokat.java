package com.mycompany.mavenproject2;

class Wielokat extends Figura{
    int liczbaWierzcholkow;
    int liczbaBokow;
    int sumaKatowWewnetrznych;

    public Wielokat(int liczbaWierzcholkow, int liczbaBokow, int sumaKatowWewnetrznych) {
        this.liczbaWierzcholkow = liczbaWierzcholkow;
        this.liczbaBokow = liczbaBokow;
        this.sumaKatowWewnetrznych = sumaKatowWewnetrznych;
    }

    public int getLiczbaWierzcholkow() {
        return liczbaWierzcholkow;
    }

    public int getLiczbaBokow() {
        return liczbaBokow;
    }

    public int getSumaKatowWewnetrznych() {
        return sumaKatowWewnetrznych;
    }

    public void setLiczbaWierzcholkow(int liczbaWierzcholkow) {
        this.liczbaWierzcholkow = liczbaWierzcholkow;
    }

    public void setLiczbaBokow(int liczbaBokow) {
        this.liczbaBokow = liczbaBokow;
    }

    public void setSumaKatowWewnetrznych(int sumaKatowWewnetrznych) {
        this.sumaKatowWewnetrznych = sumaKatowWewnetrznych;
    }

    @Override
    protected String podajParametry() {
        return super.podajParametry(); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    protected void przesun() {
        super.przesun(); //To change body of generated methods, choose Tools | Templates.
        System.out.println("Trwa przesuwanie wielokąta");
    }

    @Override
    protected void usun() {
        super.usun(); //To change body of generated methods, choose Tools | Templates.
        System.out.println("Trwa usuwanie wielokąta");
    }

    @Override
    protected void rysuj() {
        super.rysuj(); //To change body of generated methods, choose Tools | Templates.
        System.out.println("Trwa rysowanie wielokąta o " + liczbaWierzcholkow + "wierzchołkach"); 
    }
    
    protected void oblicz(){
        sumaKatowWewnetrznych = (liczbaBokow-2)*180;
    }
}
