package pl.pollub.android.app3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import java.net.URL;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import javax.net.ssl.HttpsURLConnection;

public class MainActivity extends AppCompatActivity {

    private Button pobierzInfoBt;
    private TextView adres;
    private TextView rozmiarPliku;
    private TextView typPliku;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        this.pobierzInfoBt = findViewById(R.id.download_information_bt);
        this.adres = findViewById(R.id.address_et);
        this.rozmiarPliku = findViewById(R.id.file_size_value_tv);
        this.typPliku = findViewById(R.id.file_type_value_tv);
        this.pobierzInfoBt.setOnClickListener(view -> pobierzInfo());
    }

    private void pobierzInfo() {
        ExecutorService executorService = Executors.newSingleThreadExecutor();
        executorService.execute(() -> {
            HttpsURLConnection polaczenie = null;
            try {
                URL url = new URL(this.adres.getText().toString());
                polaczenie = (HttpsURLConnection) url.openConnection();
                polaczenie.setRequestMethod("GET");
                long length = polaczenie.getContentLengthLong();
                runOnUiThread(() -> this.rozmiarPliku.setText(Long.toString(length)));
                String contentType = polaczenie.getContentType();
                runOnUiThread(() -> this.typPliku.setText(contentType));
            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                if (polaczenie != null) polaczenie.disconnect();
            }
        });
    }
}