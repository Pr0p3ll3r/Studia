package com.mycompany.Kulki;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Pisarz { 
    public void prostyZapis(String linia){
        File f=new File("Plik.txt");
        try {
            FileWriter writer=new FileWriter(f, true);            
            writer.append(linia);        
            writer.close();
        } catch (IOException ex) {
            System.out.println("Błąd " + ex.getMessage());
        }      
    }
    
    public void prostyOdczyt(String nazwaPliku, ArrayList<Kula> kule){
        File f=new File(nazwaPliku);
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(f));
            String linia="";
            try {
                while((linia=br.readLine())!=null){
                    String[] split=linia.split(":");
                    int x = Integer.parseInt(split[0]);
                    int y = Integer.parseInt(split[1]);
                    int s = Integer.parseInt(split[2]);
                    Kula k = new Kula(x,y,s);
                    kule.add(k);
                }
            } catch (IOException ex) {
                 System.out.println("Błąd " + ex.getMessage());
            }            
        } catch (FileNotFoundException ex) {
            System.out.println("Błąd " + ex.getMessage());
        }
    }
}
