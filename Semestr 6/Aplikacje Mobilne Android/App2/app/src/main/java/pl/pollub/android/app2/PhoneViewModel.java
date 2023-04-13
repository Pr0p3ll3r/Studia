package pl.pollub.android.app2;

import android.app.Application;

import androidx.annotation.NonNull;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;

import java.util.List;

public class PhoneViewModel extends AndroidViewModel {
    private PhoneRepository repository;
    private LiveData<List<Phone>> phoneList;
    public PhoneViewModel(@NonNull Application application) {
        super(application);
        this.repository = new PhoneRepository(application);
        this.phoneList = this.repository.getPhoneList();
    }

    public LiveData<List<Phone>> getPhoneList() {
        return phoneList;
    }
}
