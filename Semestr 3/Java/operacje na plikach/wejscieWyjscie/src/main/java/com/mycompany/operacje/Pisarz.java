package com.mycompany.operacje;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Pisarz { 
    void odczyt(){
        File f = new File("Plik2.txt");
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(f));
            String line="";
            try {
                while((line=br.readLine())!=null){
                    System.out.println(line);
                }
            } catch (IOException ex) {
                Logger.getLogger(Pisarz.class.getName()).log(Level.SEVERE, null, ex);
            }
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Pisarz.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    public void prostyZapis(){
        File f=new File("Plik.txt");
        try {
            FileWriter writer=new FileWriter(f, true);
            
            for (int i = 0; i < 10; i++) {
                writer.append("Linia tekstu nr "+i+"\n");
            }
            
            writer.close();
        } catch (IOException ex) {
            System.out.println("Błąd " + ex.getMessage());
        }      
    }
    
    public void prostyOdczyt(String nazwaPliku){
        File f=new File(nazwaPliku);
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(f));
            String linia="";
            try {
                while((linia=br.readLine())!=null){
                    System.out.println(linia);
                }
            } catch (IOException ex) {
                 System.out.println("Błąd " + ex.getMessage());
            }            
        } catch (FileNotFoundException ex) {
            System.out.println("Błąd " + ex.getMessage());
        }
    }
}
