package com.mycompany.watki;

import static java.lang.Thread.sleep;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Producent implements Runnable{
    ProducentConsument pc;
    Random rnd = new Random();    
    
    public Producent(ProducentConsument pc){
         this.pc=pc;
    }
    
    @Override
    public void run() {
        while(true){
            pc.produce();
            try {
                sleep(rnd.nextInt(1000));
            } catch (InterruptedException ex) {
                Logger.getLogger(Producent.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
   
}
