package com.mycompany.watki;

import java.util.Random;

public class Watek implements Runnable{

    int nr=0;
    
    public Watek(int nr)
    {
        this.nr=nr;
    }
    
    @Override
    public void run() {
        Random random = new Random();
        int a = random.nextInt(101);
        System.out.println("Watek nr "+nr+" wylosowal liczbe "+ a);
    }

    public static void main(String[] args) {      
        Watek w1 = new Watek(1);
        Thread t1 = new Thread(w1);
        Watek w2 = new Watek(2);
        Thread t2 = new Thread(w2);
        t1.start();
        t2.start();
    }
}
