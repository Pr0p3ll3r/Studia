package com.mycompany.watki;

import static java.lang.Thread.sleep;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Frying implements Runnable{

    @Override
    public void run() {     

        System.out.println("Usmażono");
        notify();
    }

}
