
package com.mycompany.wspolbieznosc;

import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;


public class ProducentConsumet {
    int[] buffer=new int[10];
    int ile=0;
    Random r=new Random();
    
    public ProducentConsumet(){
        
    }
    
    public synchronized void produce(){
        while(ile>8)
            try {
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(ProducentConsumet.class.getName()).log(Level.SEVERE, null, ex);
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
                Logger.getLogger(ProducentConsumet.class.getName()).log(Level.SEVERE, null, ex);
            }
        System.out.println("Skonsumowano "+--ile+": "+buffer[ile]);
        buffer[ile]=-1; 
        notify();
    }
    
}
