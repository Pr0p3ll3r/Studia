package com.mycompany.mavenproject1;

public class NewClass {
    public static void main(String[] args) {
        String ciag = "abacgdgaaaooda";
            

        zadanie1('a', ciag);
    }
    
    static void zadanie1(char znak, String s)
    {
        int ileRazy=0;
        int i=s.indexOf(znak);
        if(i != -1)
        {
            ileRazy++;
        }
        for (int j = i; j < s.length(); j++) 
        {
            int index=s.indexOf(znak,i);
            if(j != -1)
            {
                ileRazy++;
            }
            else break;
        }
        System.out.println("Znak "+znak +" wystepuje " + ileRazy + " razy");
    }
}
