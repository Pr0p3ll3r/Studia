package com.mycompany.operacje;

import java.util.Random;

public class Pesel {

    public Pesel() {
    }

    static int plec() {
        int plec1 = (int) Math.floor(Math.random() * (2 - 1 + 1) + 1);
        int[] mecz = new int[]{1, 3, 5, 7, 9};
        int[] kob = new int[]{0, 2, 4, 6, 8};
        if (plec1 == 1) {
            int m = mecz[new Random().nextInt(mecz.length)];
            return m;
        } else if (plec1 == 2) {
            int k = kob[new Random().nextInt(kob.length)];
            return k;
        }
        return 0;
    }

    static int ctrSum(String odp10) {

        int a1 = Character.getNumericValue(odp10.charAt(0)) * 1 % 10;
        int a2 = Character.getNumericValue(odp10.charAt(1)) * 3 % 10;
        int a3 = Character.getNumericValue(odp10.charAt(2)) * 7 % 10;
        int a4 = Character.getNumericValue(odp10.charAt(3)) * 9 % 10;
        int a5 = Character.getNumericValue(odp10.charAt(4)) % 10;
        int a6 = Character.getNumericValue(odp10.charAt(5)) * 3 % 10;
        int a7 = Character.getNumericValue(odp10.charAt(6)) * 7 % 10;
        int a8 = Character.getNumericValue(odp10.charAt(7)) * 9 % 10;
        int a9 = Character.getNumericValue(odp10.charAt(8)) % 10;
        int a10 = Character.getNumericValue(odp10.charAt(9)) * 3 % 10;
        int summ = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10;

        summ = summ % 10;
        int odp = 10 - summ;
        if (odp == 10) {
            odp = 0;
        }
        return odp;
    }

    static void peselgen(int rok, int mies, int dzien, int licznik) {
        String year, month, day;
        int yrfld = rok % 100;
        if (yrfld < 10) {
            year = "0" + String.valueOf(yrfld);
        } else {
            year = String.valueOf(yrfld);
        }
        if (dzien < 10) {
            day = "0" + String.valueOf(dzien);
        } else {
            day = "" + String.valueOf(dzien);
        }
        int monthFields = mies + 1;
        if (rok >= 1800 && rok <= 1899) {
            monthFields += 80;
        }
        if (rok >= 2000 && rok <= 2099) {
            monthFields += 20;
        }
        if (rok >= 2100 && rok <= 2199) {
            monthFields += 40;
        }
        if (rok >= 2200 && rok <= 2299) {
            monthFields += 60;
        }
        if (monthFields < 10) {
            month = "0" + monthFields;
        } else {
            month = "" + monthFields;
        }
        String rnd;
        int rndint = (int) Math.floor(Math.random() * (999 - 0 + 1) + 0);
        if (rndint < 10) {
            rnd = "00" + String.valueOf(rndint);
        } else if (rndint < 100) {
            rnd = "0" + String.valueOf(rndint);
        } else {
            rnd = "" + String.valueOf(rndint);
        }
        String plc = String.valueOf(plec());
        String odp10 = year + month + day + rnd + plc;
        int ctr = ctrSum(odp10);
        odp10 = year + month + day + rnd + plc + String.valueOf(ctr);
        System.out.println(odp10);
    }

    static void generateday() {
        int counter = 1;
        for (int k = 1900; k <= 2022; k++) {
            for (int i = 1; i < 13; i++) {

                if (i < 12) {

                    if (i == 4 || i == 6 || i == 9 || i == 11) {
                        for (int j = 1; j <= 30; j++) {

                            peselgen(k, i, j, counter);
                            counter++;
                        }
                    } else {
                        for (int j = 1; j <= 31; j++) {
                            // System.out.print(j + " ");
                            peselgen(k, i, j, counter);
                            counter++;
                        }
                    }
                } else if (i == 12) {

                    if (k % 4 == 0) {
                        for (int j = 1; j <= 29; j++) {

                            peselgen(k, i, j, counter);
                            counter++;
                        }
                    } else {
                        for (int j = 1; j <= 28; j++) {
                            peselgen(k, i, j, counter);
                            counter++;
                        }
                    }
                }
            }
            
        }
         System.out.println(counter);
    }
   

    public static void main(String[] args) {
        generateday();
    }
}
