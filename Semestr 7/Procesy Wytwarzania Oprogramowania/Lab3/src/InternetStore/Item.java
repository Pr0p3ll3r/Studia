package InternetStore;

public class Item {
    private String name;
    private Double price;
    private int status;
    public static final int STATUS_NEW = 0;
    public static final int STATUS_SOLD = 1;
    public Item(String name, Double price, int status) {
        this.name = name;
        this.price = price;
        this.status = status;
    }
    public Item produceItem(String name, Double price){
        return new Item(name, price, STATUS_NEW);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    public int getStatus() {
        return status;
    }

    public void setStatus(int status) {
        this.status = status;
    }
}
