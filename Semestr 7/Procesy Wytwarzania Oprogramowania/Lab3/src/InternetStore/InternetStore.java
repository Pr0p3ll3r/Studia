package InternetStore;

import java.util.ArrayList;

public class InternetStore {
    ArrayList<Item> items = new ArrayList<>();
    public void addItemToStorage(Item item){
        items.add(item);
    }
    public void removeItemFromStorage(Item item){
        items.remove(item);
    }
    public void sellItemFromStorage(int storageIndex){
        Item item = items.get(storageIndex);
        item.setStatus(Item.STATUS_SOLD);
    }
}