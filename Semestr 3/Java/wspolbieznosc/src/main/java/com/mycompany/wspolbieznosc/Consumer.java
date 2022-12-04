/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.wspolbieznosc;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Consumer extends Thread {
    ProducentConsumet pc;
    Random r=new Random();
    
    public Consumer(ProducentConsumet pc){
        this.pc=pc;
    }

    @Override
    public void run() {
        //super.run(); //To change body of generated methods, choose Tools | Templates.
        while(true){
            pc.consume();
            try {
                sleep(r.nextInt(1000));
            } catch (InterruptedException ex) {
                Logger.getLogger(Producent.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }  
}
