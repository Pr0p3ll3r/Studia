package com.mycompany.watki;

import static java.lang.Thread.sleep;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Rolling implements Runnable{

    @Override
    public void run() {
        try {
            sleep(10);
        } catch (InterruptedException ex) {
            Logger.getLogger(Rolling.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println("Zwinięto");
        notify();
    }

}
