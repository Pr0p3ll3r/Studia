package pl.pollub.android.app2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;

public class PhoneActivity extends AppCompatActivity {
    public static final String MANUFACTURER_KEY = "MANUFACTURER_KEY";
    public static final String MODEL_KEY = "MODEL_KEY";
    public static final String ANDROID_VERSION_KEY = "ANDROID_VERSION_KEY";
    public static final String WEBSITE_KEY = "WEBSITE_KEY";
    public static final String PHONE_ID_KEY = "PHONE_ID_KEY";
    private EditText manufacturerEt;
    private EditText modelEt;
    private EditText androidVersionEt;
    private EditText websiteEt;
    private Button saveBt;
    private Long phoneId = 0L;
    private Button cancelBt;
    private Button goToWebsiteBt;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_phone);
        this.manufacturerEt = findViewById(R.id.manufacturer_et);
        this.modelEt = findViewById(R.id.model_et);
        this.androidVersionEt = findViewById(R.id.android_version_et);
        this.websiteEt = findViewById(R.id.website_et);
        this.saveBt = findViewById(R.id.save_bt);
        this.saveBt.setOnClickListener(view -> saveNewPhone());
        this.cancelBt = findViewById(R.id.cancel_bt);
        this.cancelBt.setOnClickListener(view -> cancelPhone());
        this.goToWebsiteBt = findViewById(R.id.website_bt);
        this.goToWebsiteBt.setOnClickListener(view -> goToWebsite());
        Intent intent = getIntent();
        if(intent != null) {
            Bundle bundle = intent.getExtras();
            if(bundle != null) {
                this.manufacturerEt.setText(bundle.getString(MANUFACTURER_KEY));
                this.modelEt.setText(bundle.getString(MODEL_KEY));
                this.androidVersionEt.setText(bundle.getString(ANDROID_VERSION_KEY));
                this.websiteEt.setText(bundle.getString(WEBSITE_KEY));
                this.phoneId = bundle.getLong(PHONE_ID_KEY);
            }
        }
    }

    private void goToWebsite() {
        String url = this.websiteEt.getText().toString();
        if(url.isEmpty()) {
            this.websiteEt.setError("Website can't be empty");
            return;
        }

        if (!url.startsWith("http://") && !url.startsWith("https://")) {
            url = "http://" + url;
        }
        Intent website = new Intent("android.intent.action.VIEW", Uri.parse(url));
        startActivity(website);
    }

    private void cancelPhone() {
        Intent intent = new Intent();
        setResult(RESULT_CANCELED, intent);
        finish();
    }

    private void saveNewPhone() {
        String manufacturer = this.manufacturerEt.getText().toString();
        String model = this.modelEt.getText().toString();
        String androidVersion = this.androidVersionEt.getText().toString();
        String website = this.websiteEt.getText().toString();
        if(manufacturer.isEmpty()) {
            this.manufacturerEt.setError("Manufacturer can't be empty");
            return;
        }
        if(model.isEmpty()) {
            this.modelEt.setError("Model can't be empty");
            return;
        }
        if(androidVersion.isEmpty()) {
            this.androidVersionEt.setError("Version can't be empty");
            return;
        }
        if(website.isEmpty()) {
            this.websiteEt.setError("Website can't be empty");
            return;
        }
        Intent intent = new Intent();
        Bundle bundle = new Bundle();
        bundle.putString(this.MANUFACTURER_KEY, manufacturer);
        bundle.putString(this.MODEL_KEY, model);
        bundle.putString(this.ANDROID_VERSION_KEY, androidVersion);
        bundle.putString(this.WEBSITE_KEY, website);
        bundle.putLong(this.PHONE_ID_KEY, this.phoneId);
        intent.putExtras(bundle);
        setResult(RESULT_OK, intent);
        finish();
    }
}