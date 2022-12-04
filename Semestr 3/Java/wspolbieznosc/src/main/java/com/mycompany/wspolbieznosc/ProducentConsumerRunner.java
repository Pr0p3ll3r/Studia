package com.mycompany.wspolbieznosc;

public class ProducentConsumerRunner extends Thread {
    
    
    public static void main(String[] args) {
        ProducentConsumet pc=new ProducentConsumet();
        Thread t1=new Thread(new Producent(pc));
        Thread t2=new Thread(new Consumer(pc));
        t1.start();
        t2.start();
    }

    
    
    
}
