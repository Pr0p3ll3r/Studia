package Liskov;

public class Admin extends SuperUser{
    Admin (String username, String login, String pwdHash, double age){
        super(username, "Admin" + login, pwdHash, age);
    }
}