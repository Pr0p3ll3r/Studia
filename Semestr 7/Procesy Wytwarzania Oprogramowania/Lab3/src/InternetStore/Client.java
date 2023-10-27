package InternetStore;

public class Client {
    private String name;
    private String phone;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void changeClientData(Client client, String name, String phone){
        client.setName(name);
        client.setPhone(phone);
    }
}
