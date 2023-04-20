package pl.pollub.android.app2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;

public class PhoneActivity extends AppCompatActivity {
    public static final String MANUFACTURER_KEY = "MANUFACTURER_KEY";
    public static final String MODEL_KEY = "MODEL_KEY";
    public static final String ANDROID_VERSION_KEY = "ANDROID_VERSION_KEY";
    public static final String WEBSITE_KEY = "WEBSITE_KEY";
    private EditText manufacturerEt;
    private EditText modelEt;
    private EditText androidVersionEt;
    private EditText websiteEt;
    private Button saveBt;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_phone);
        this.manufacturerEt = findViewById(R.id.manufacturer_et);
        this.modelEt = findViewById(R.id.model_et);
        this.androidVersionEt = findViewById(R.id.android_version_et);
        this.websiteEt = findViewById(R.id.website_et);
        this.saveBt = findViewById(R.id.save_bt);
        this.saveBt.setOnClickListener(view -> {
            saveNewPhone();
        });
    }

    private void saveNewPhone() {
        Intent intent = getIntent();
        Bundle bundle = new Bundle();
        bundle.putString(this.MANUFACTURER_KEY, this.manufacturerEt.getText().toString());
        bundle.putString(this.MODEL_KEY, this.modelEt.getText().toString());
        bundle.putString(this.ANDROID_VERSION_KEY, this.androidVersionEt.getText().toString());
        bundle.putString(this.WEBSITE_KEY, this.websiteEt.getText().toString());
        intent.putExtras(bundle);
        finish();
    }
}