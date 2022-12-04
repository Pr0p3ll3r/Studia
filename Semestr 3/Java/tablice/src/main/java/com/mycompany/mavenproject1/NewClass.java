package com.mycompany.mavenproject1;

import java.util.Random;

public class NewClass {
       
    private static int[] createTable(int size)
    {
        int[] table = new int[size];
        for (int i = 0; i < size; i++) 
        {
            table[i]=i;
        }
        return table;
    }
    
    private static void displayTable(int[] table)
    {
        for (int i = 0; i < table.length; i++) 
        {
            if(i%10==0)
                System.out.println();
            
            if(i<10)
                System.out.print("0"+i+", ");
            else
                System.out.print(i+", ");
        }
        
        System.out.println();
        
        for (int i = 0; i < 10; i++) 
        {
            System.out.print(average(i,table)+", ");
        }
    }
    
    private static double average(int index, int[] table){
        double average=0;
        for (int i = index; i < table.length; i+=10) 
        {
            average+=table[i];
        }
        average/=table.length;
        return average;
    }
    
    private static void createTable2()
    {
        Random rnd = new Random();
        int size = (10+rnd.nextInt(20)%11);
        System.out.println("Size: "+size);
        int table2[][] = new int[size][size];
        
        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++) {
                if (j==i) {
                    table2[i][j]=rnd.nextInt(2)==0?1:-1;
                }
                else{
                    table2[i][j]=(rnd.nextInt(41)-20);
                }
                System.out.print(table2[i][j]+"\t");
            } 
            System.out.print("\n");
        }
    }
    
    public static void main(String[] args) {
        int[] table = createTable(100);
        displayTable(table);
        createTable2();
    }
}
