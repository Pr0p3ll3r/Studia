package pl.pollub.android.app1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private boolean isImieEtOk;
    private boolean isNazwiskoEtOk;
    private boolean isLiczbaOcenEtOk;
    private boolean isPotwierdzEtWidoczny;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        EditText imieEt = findViewById(R.id.imie_et);
        imieEt.setOnFocusChangeListener((v, hasFocus) -> {
            if(hasFocus) return;
            this.isImieEtOk = sprawdzEt(imieEt, getString(R.string.imie_et_err));
            sprawdzPotwierdzBtWidoczny();
        });

        EditText nazwiskoEt = findViewById(R.id.nazwisko_et);
        nazwiskoEt.setOnFocusChangeListener((v, hasFocus) -> {
            if(hasFocus) return;
            this.isNazwiskoEtOk = sprawdzEt(nazwiskoEt, getString(R.string.nazwisko_et_err));
            sprawdzPotwierdzBtWidoczny();
        });

        EditText liczbaOcenEt = findViewById(R.id.liczba_ocen_et);
        liczbaOcenEt.setOnFocusChangeListener((v, hasFocus) -> {
            if(hasFocus) return;
            this.isLiczbaOcenEtOk = sprawdzLiczbeOcen(liczbaOcenEt, getString(R.string.liczba_ocen_et_err));
            sprawdzPotwierdzBtWidoczny();
        });
    }

    private boolean sprawdzEt(EditText editText, String info) {
        if("".equals(editText.getText().toString())){
            editText.setError(info);
            Toast.makeText(this, info, Toast.LENGTH_LONG).show();
            return false;
        }
        return true;
    }

    private boolean sprawdzLiczbeOcen(EditText editText, String info)  {
        int o;
        if("".equals(editText.getText().toString())){
            o = 0;
        } else {
            try {
                o = Integer.parseInt(editText.getText().toString());
            } catch (NumberFormatException e) {
                o = 0;
            }
        }
        if(o < 5 || o > 15) {
            editText.setError(info);
            Toast.makeText(this, info, Toast.LENGTH_LONG).show();
            return false;
        }
        return true;
    }

    private void sprawdzPotwierdzBtWidoczny() {
        this.isPotwierdzEtWidoczny = this.isImieEtOk && this.isNazwiskoEtOk && this.isLiczbaOcenEtOk;
        Button potwierdzBt = findViewById(R.id.potwierdz_bt);
        potwierdzBt.setVisibility(this.isPotwierdzEtWidoczny ? View.VISIBLE : View.GONE);
    }
}