
package com.mycompany.wspolbieznosc;

import static java.lang.Thread.sleep;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Watek implements Runnable{
    Random r=new Random();
    int nr,wylosowano;
    int suma_wewnetrzna_watku=0;
    Liczba l;

    public Watek(int nr, Liczba l) {
        this.nr = nr;
        this.l=l;
    }


    @Override
    public void run() {
        while(true){
            wylosowano=r.nextInt(100);
            System.out.println("Watek: "+nr+" generated: "+wylosowano); 
            l.suma+=wylosowano;
            suma_wewnetrzna_watku+=wylosowano;
            System.out.println("Watek: "+nr+" suma: "+suma_wewnetrzna_watku);
            System.out.println("Suma wspólna: "+l.suma);
           try {
                sleep(100);
           } catch (InterruptedException ex) {
                Logger.getLogger(Watek.class.getName()).log(Level.SEVERE, null, ex);
          }
            
        }
    }
    
    public static void main(String[] args) {
        Liczba l=new Liczba();
        Watek w1=new Watek(1,l);
        Thread t=new Thread(w1);
        t.start();
        
        Watek w2=new Watek(2,l);
        Thread t2=new Thread(w2);
        t2.start();
    }
    
}
