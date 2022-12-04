package com.mycompany.lambda;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class Lambda {
    public static void main(String[] args) {
        ArrayList<String> przedmioty = new ArrayList<String>();
        przedmioty.add("Matematyka");
        przedmioty.add("Java");
        przedmioty.add("C++");
        print(przedmioty, p->System.out.println(p));
        
        Integer[] liczby={5,2,3,1,6};
        Comparator<Integer> sort = (Integer i1, Integer i2)->(i1.compareTo(i2));
        Arrays.sort(liczby,sort);
        System.out.println("Posortowana lista"+ Arrays.asList(liczby));
        
        Comparator<String> sort2 = (String s1, String s2)->(Integer.valueOf(s1.length()).compareTo(Integer.valueOf(s2.length())));
        przedmioty.sort(sort2);
        System.out.println("Posortowana lista"+ przedmioty);
    }
    
    private static void print(ArrayList<String> przedmioty, Wypisz w)
    {
        for (String string : przedmioty) {
            w.test(string);
        }
    }
    
    interface Wypisz
    {   
        void test(String string);
    }
}

