package com.mycompany.watki;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ProducentConsument {
    int[] buffer=new int[10];
    int ile=0;
    Random r=new Random();
    Thread frying = new Thread(new Frying());
    Thread lubrication = new Thread(new Lubrication());
    Thread rolling = new Thread(new Rolling());
    
    public synchronized void produce(){
        while(ile>8)
            try {
                frying.start();
                lubrication.join();
                rolling.join();
            } catch (InterruptedException ex) {
                Logger.getLogger(ProducentConsument.class.getName()).log(Level.SEVERE, null, ex);
            }
        buffer[ile]=r.nextInt(101); 
        System.out.println("Wyprodukowano "+ile +": "+buffer[ile]);
        ile++;
        notify();
    }
    
    public synchronized void consume(){
        while(ile<1)
            try {
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(ProducentConsument.class.getName()).log(Level.SEVERE, null, ex);
            }
        System.out.println("Skonsumowano "+--ile+": "+buffer[ile]);
        buffer[ile]=-1; 
        notify();
    }
    
}
