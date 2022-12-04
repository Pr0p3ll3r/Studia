package com.mycompany.watki;

import static java.lang.Thread.sleep;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Consumer implements Runnable{
    ProducentConsument pc;
    Random rnd = new Random();  
         
    public Consumer(ProducentConsument pc){
         this.pc=pc;
    }
    
    @Override
    public void run() {
        while(true){
            pc.consume();
            try {
                sleep(rnd.nextInt(1000));
            } catch (InterruptedException ex) {
                Logger.getLogger(Consumer.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

}
