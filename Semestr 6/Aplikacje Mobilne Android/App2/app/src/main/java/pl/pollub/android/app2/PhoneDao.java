package pl.pollub.android.app2;

import androidx.lifecycle.LiveData;
import androidx.room.Dao;
import androidx.room.Insert;
import androidx.room.OnConflictStrategy;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface PhoneDao {
    @Insert(onConflict = OnConflictStrategy.ABORT)
    void insert(Phone phone);
    @Update()
    void update(Phone phone);
    @Query("Select * from phones")
    LiveData<List<Phone>> findAllPhones();
}
