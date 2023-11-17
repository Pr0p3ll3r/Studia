package org.example.calculations;

public class Thermometer {
    int minTemp;
    int maxTemp;
    int currentTemp;
    Thermometer(){ }
    Thermometer(int minTemp, int maxTemp){
        this.minTemp = minTemp;
        this.maxTemp = maxTemp;
    }
    public static Thermometer createInstance(int minTemp, int maxTemp) {
        return new Thermometer(minTemp, minTemp);
    }
    public int getCurrentTemp(){
        return currentTemp;
    }
    public void setCurrentTemp(Object currentTemp){
        if (currentTemp instanceof Integer) {
            this.currentTemp = (Integer) currentTemp;
        } else {
            throw new IllegalArgumentException("CurrentTemp must be an Integer.");
        }
    }
    public int addDegrees(Object degrees){
        if (degrees instanceof Integer) {
            currentTemp += (Integer) degrees;
            return currentTemp;
        } else {
            throw new IllegalArgumentException("Degrees to add must be an Integer.");
        }
    }
    public int subtractDegrees(Object degrees){
        if (degrees instanceof Integer) {
            currentTemp -= (Integer) degrees;
            return currentTemp;
        } else {
            throw new IllegalArgumentException("Degrees to subtract must be an Integer.");
        }
    }
    public boolean isBelowZero(){
        return currentTemp<0?true:false;
    }
}