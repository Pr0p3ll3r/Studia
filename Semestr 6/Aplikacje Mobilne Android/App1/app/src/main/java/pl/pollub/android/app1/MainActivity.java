package pl.pollub.android.app1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        EditText imieEt = findViewById(R.id.imie_et);
        imieEt.setOnFocusChangeListener((v, hasFocus) -> {
            if(hasFocus) return;
            if("".equals(imieEt.getText().toString())){
                imieEt.setError(getString(R.string.imie_et_err));
                Toast.makeText(this, R.string.imie_et_err, Toast.LENGTH_LONG).show();
            }
        });
        EditText nazwiskoEt = findViewById(R.id.nazwisko_et);
        nazwiskoEt.setOnFocusChangeListener((v, hasFocus) -> {
            if(hasFocus) return;
            if("".equals(nazwiskoEt.getText().toString())){
                nazwiskoEt.setError(getString(R.string.nazwisko_et_err));
                Toast.makeText(this, R.string.nazwisko_et_err, Toast.LENGTH_LONG).show();
            }
        });
    }
}