/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.wspolbieznosc;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Producent extends Thread {
    ProducentConsumet pc;
    Random r=new Random();

    public Producent(ProducentConsumet pc){
        this.pc=pc;
    }
    @Override
    public void run() {
        //super.run(); //To change body of generated methods, choose Tools | Templates.
        while(true){
            pc.produce();
            try {
                sleep(r.nextInt(100));
            } catch (InterruptedException ex) {
                Logger.getLogger(Producent.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }   
}
