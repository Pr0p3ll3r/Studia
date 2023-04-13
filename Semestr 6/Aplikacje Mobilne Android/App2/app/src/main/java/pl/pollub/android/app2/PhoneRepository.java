package pl.pollub.android.app2;

import android.app.Application;

import androidx.lifecycle.LiveData;

import java.util.List;

public class PhoneRepository {
    private PhoneDao dao;
    LiveData<List<Phone>> phoneList;

    public PhoneRepository(Application application) {
        PhonesDatabase database = PhonesDatabase.getDatabase(application);
        this.dao = database.phoneDao();
        this.phoneList = dao.findAllPhones();
    }

    public LiveData<List<Phone>> getPhoneList() {
        return phoneList;
    }

    public void insert(Phone phone){
        this.dao.insert(phone);
    }

    public void update(Phone phone){
        this.dao.update(phone);
    }
}
