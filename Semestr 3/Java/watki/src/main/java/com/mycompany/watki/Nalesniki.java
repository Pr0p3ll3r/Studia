package com.mycompany.watki;

public class Nalesniki extends Thread{
    
    public static void main(String[] args) {
        ProducentConsument pc = new ProducentConsument();
        Thread producent = new Thread(new Producent(pc));
        producent.start();
    }
}
