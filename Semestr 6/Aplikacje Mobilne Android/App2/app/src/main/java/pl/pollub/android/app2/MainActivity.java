package pl.pollub.android.app2;

import android.content.Intent;
import android.os.Bundle;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.ViewModelProvider;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

public class MainActivity extends AppCompatActivity {
    private RecyclerView phoneListRv;
    private PhoneAdapter adapter;
    private PhoneViewModel phoneViewModel;
    private ActivityResultLauncher<Intent> launcher;
    private FloatingActionButton addPhoneFab;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        this.phoneListRv = findViewById(R.id.phone_list_rv);
        this.addPhoneFab = findViewById(R.id.add_phone_fab);
        this.addPhoneFab.setOnClickListener(view -> newPhone());
        this.adapter = new PhoneAdapter(this.getLayoutInflater());
        this.phoneListRv.setAdapter(this.adapter);
        this.phoneListRv.setLayoutManager(new LinearLayoutManager(this));
        this.phoneViewModel = new ViewModelProvider(this).get(PhoneViewModel.class);
        this.phoneViewModel.getPhoneList().observe(this, phones -> {
            this.adapter.setPhoneList(phones);
        });
        this.launcher = registerForActivityResult(new ActivityResultContracts.StartActivityForResult(), result -> {
            addPhone(result);
        });
    }

    private void newPhone() {
        Intent intent = new Intent(this, PhoneActivity.class);
        setResult(RESULT_OK, intent);
        this.launcher.launch(intent);
    }

    private void addPhone(ActivityResult result) {
        if(result.getResultCode() == RESULT_OK){
            Bundle bundle = result.getData().getExtras();
            String manufactrer = bundle.getString(PhoneActivity.MANUFACTURER_KEY);
            String model = bundle.getString(PhoneActivity.MODEL_KEY);
            String androidVersion = bundle.getString(PhoneActivity.ANDROID_VERSION_KEY);
            String website = bundle.getString(PhoneActivity.WEBSITE_KEY);
            this.phoneViewModel.insert(new Phone(manufactrer, model, androidVersion, website));
        }
    }
}