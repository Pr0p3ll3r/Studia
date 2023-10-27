package Liskov;

public class User{
    public String username;
    protected String login;
    private String pwdHash;
    UserService service;
    protected boolean loggedIn = false;
    public double[] permissions;
    User(String username, String login, String pwd){
        this.username = username;
        this.login = login;
        this.pwdHash = SHA256.hash(pwd);
    }
    public double[] getPermissions(){
        return permissions;
    }
    public void setPermissions(double[] perms){
        System.out.println("Set permissions");
        permissions = perms;
    }
    public void logIn(){
        if(pwdHash = SHA256.hash(pwd)){
            service.logIn(username, pwdHash);
            loggedIn = true;
        }
    }
    public void logOut(){
        service.logOut(username);
    }
}