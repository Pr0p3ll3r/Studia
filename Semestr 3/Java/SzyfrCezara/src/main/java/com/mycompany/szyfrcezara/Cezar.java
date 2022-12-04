package com.mycompany.szyfrcezara;

import java.util.Scanner;

public class Cezar {
    public static void main(String[] args) {
        String text = text();
        System.out.println("Tekst po zaszyfrowaniu: "+caesarCiper(text));
    }
    
    private static String text(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Podaj tekst");
        String text=scanner.nextLine();
        return text;
    }
    
    private static String caesarCiper(String s){
        String encrypted="";
        for (int i = 0; i < s.length(); i++) {
           if (Character.isUpperCase(s.charAt(i)))
           {
               int characterIndex = (char)(s.charAt(i)) - (char)('A');
               int characterShifted = (characterIndex + 3) % 26 +  (char)('A');
               encrypted += (char)(characterShifted);
           }
           else if (Character.isLowerCase(s.charAt(i)))
           {
                int characterIndex = (char)(s.charAt(i)) - (char)('a');
                int characterShifted = (characterIndex + 3) % 26 +  (char)('a');
                encrypted += (char)(characterShifted);
           }
           else if (Character.isDigit(s.charAt(i)))
           {
               int  characterNew = ((int)(s.charAt(i)) + 3) % 10;
               encrypted += (char)(characterNew);
           }
           else
           {
               encrypted += s.charAt(i);
           }         
        }
        return encrypted;
    }
}
