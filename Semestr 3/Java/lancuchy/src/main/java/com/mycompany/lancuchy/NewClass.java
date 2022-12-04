package com.mycompany.lancuchy;

import java.util.Scanner;

public class NewClass {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = "Ala ma kota";
        System.out.println("Podaj znak: ");
        char c = scanner.next().charAt(0);
        System.out.println("Znak "+c+" wystąpił "+checkInString(line,c)+" razy");
        System.out.println("Suma kodów ascii małych liter i cyfr wynosi: "+sumAscii(line));
        System.out.println(numberToChar());
    }
       
    private static int checkInString(String s, char c){
        int a=0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)==c)
                a++;
        }
        return a;
    }
    
    private static int sumAscii(String s){
        int a=0;
        for (int i = 0; i < s.length(); i++) {
            int code = s.codePointAt(i);
            if((code>=48 && code<=57 )|| (code >= 97 && code <=122))
                a+=code;
        }
        return a;
    }
    
    private static char numberToChar(){
        Scanner scanner = new Scanner(System.in);
        int a=0;
        do{
            System.out.println("Podaj liczbe od 33 do 126");
            a=scanner.nextInt();
        }while(a<=33 || a>=126);
        return (char)a;
        
    }
}
