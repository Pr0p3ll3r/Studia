package FoodDelivery;

import java.util.ArrayList;
import java.util.Random;

class FoodDelivery{
    private String orderId;
    private int totalBill;
    public String getOrderId() {
        return orderId;
    }
    public void setOrderId(String orderId){
        Random random = new Random();
        this.orderId = orderId + "-" + random.nextInt(100);
    }
    public int getTotalBill() {
        return totalBill;
    }
    public void setTotalBill(int totalBill){
        this.totalBill += totalBill;
    }
    public void prepareOrder(Customer customer, ArrayList<Item> items){
        String orderedItems = "";
        for (Item item: items) {
            orderedItems += item.getItemName() + " ";
        }
        System.out.println("Preparing order for customer -"
                + customer.getCustomerName()
                + " who has ordered "
                + orderedItems);
    }
    public void calculateBill(ArrayList<Item> items){
        for (Item item: items) {
            Random rand = new Random();
            int totalAmt = rand.nextInt(100) * item.getQuantity();
            setTotalBill(totalAmt);
        }
        System.out.println("Order with order id "
                + getOrderId()
                + " has a total bill amount of "
                + getTotalBill());
    }
    public void delivery(Customer customer){
        System.out.println("Delivering the order for Customer"+customer.getCustomerName());
        System.out.println("Order with order id as "+ getOrderId() + " being delivered.");
        System.out.println("Order is to be delivered to: " + customer.getCustomerAddress());
    }
    public static void main(String args){
        FoodDelivery fd = new FoodDelivery();
        Customer c = new Customer();
        ArrayList<Item> items = new ArrayList<>();
        fd.setOrderId("test");
        c.setCustomerName("Ann Smiths");
        c.setCustomerAddress("New York, 1st Avenue 1234");
        Item item1 = new Item();
        item1.setItemName("Ragu");
        item1.setQuantity(1);
        Item item2 = new Item();
        item2.setItemName("Ragu2");
        item2.setQuantity(4);
        items.add(item1);
        items.add(item2);
        fd.prepareOrder(c, items);
        fd.calculateBill(items);
        fd.delivery(c);
    }
}