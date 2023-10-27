package Liskov;

public class SuperUser extends User{
    private double age;
    SuperUser (String username, String login, String pwd, double age){
        super(username, login, pwd);
        this.age = age;
    }
}