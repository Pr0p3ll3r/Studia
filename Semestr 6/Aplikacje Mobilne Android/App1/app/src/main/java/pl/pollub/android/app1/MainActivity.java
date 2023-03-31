package pl.pollub.android.app1;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContract;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityOptionsCompat;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.text.Format;
import java.util.Arrays;

public class MainActivity extends AppCompatActivity {
    private boolean isImieEtOk;
    private boolean isNazwiskoEtOk;
    private boolean isLiczbaOcenEtOk;
    private boolean isPotwierdzEtWidoczny;
    private EditText imieEt;
    private EditText liczbaOcenEt;
    private EditText nazwiskoEt;
    private Button potwierdzBt;
    public static String ILOSC_OCEN = "ILOSC_OCEN";
    public ActivityResultLauncher<Intent> launcher;
    private TextView sredniaTv;
    private Button sredniaBt;
    private float srednia;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        this.imieEt = findViewById(R.id.imie_et);
        this.liczbaOcenEt = findViewById(R.id.liczba_ocen_et);
        this.nazwiskoEt = findViewById(R.id.nazwisko_et);
        this.sredniaTv = findViewById(R.id.srednia_tv);
        this.sredniaBt = findViewById(R.id.srednia_bt);
        this.potwierdzBt = findViewById(R.id.potwierdz_bt);
        imieEt.setOnFocusChangeListener((v, hasFocus) -> {
            if(hasFocus) return;
            this.isImieEtOk = sprawdzEt(imieEt, getString(R.string.imie_et_err));
            sprawdzPotwierdzBtWidoczny();
        });

        nazwiskoEt.setOnFocusChangeListener((v, hasFocus) -> {
            if(hasFocus) return;
            this.isNazwiskoEtOk = sprawdzEt(nazwiskoEt, getString(R.string.nazwisko_et_err));
            sprawdzPotwierdzBtWidoczny();
        });

        liczbaOcenEt.setOnFocusChangeListener((v, hasFocus) -> {
            if(hasFocus) return;
            this.isLiczbaOcenEtOk = sprawdzLiczbeOcen(liczbaOcenEt, getString(R.string.liczba_ocen_et_err));
            sprawdzPotwierdzBtWidoczny();
        });

        this.launcher = this.registerForActivityResult(new ActivityResultContracts.StartActivityForResult(), result -> {
           obliczSrednia(result);
        });

        potwierdzBt.setOnClickListener(v -> {
            sprawdzPotwierdzBtWidoczny();
            if(this.isPotwierdzEtWidoczny) {
                Intent intent = new Intent(this, OcenyActivity.class);
                intent.putExtra(ILOSC_OCEN, Integer.parseInt(this.liczbaOcenEt.getText().toString()));
                this.launcher.launch(intent);
            }
        });

        sredniaBt.setOnClickListener(v -> {
            if(this.srednia >= 3) {
                Toast.makeText(this, R.string.sukces, Toast.LENGTH_LONG).show();
            }
            else {
                Toast.makeText(this, R.string.powtorka, Toast.LENGTH_LONG).show();
            }
            this.finish();
        });
    }

    @Override
    protected void onSaveInstanceState(@NonNull Bundle outState) {
        outState.putBoolean("isImieEtOk", this.isImieEtOk);
        outState.putBoolean("isNazwiskoEtOk", this.isNazwiskoEtOk);
        outState.putBoolean("isLiczbaOcenEtOk", this.isLiczbaOcenEtOk);
        outState.putFloat("srednia", this.srednia);
        super.onSaveInstanceState(outState);
    }

    @Override
    protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        this.isImieEtOk = savedInstanceState.getBoolean("isImieEtOk");
        this.isNazwiskoEtOk = savedInstanceState.getBoolean("isNazwiskoEtOk");
        this.isLiczbaOcenEtOk = savedInstanceState.getBoolean("isLiczbaOcenEtOk");
        this.srednia = savedInstanceState.getFloat("srednia");
        sprawdzPotwierdzBtWidoczny();
        pokazSrednia();
    }

    private void obliczSrednia(ActivityResult result) {
        if(result.getResultCode()==RESULT_OK) {
            Bundle pojemnik = result.getData().getExtras();
            int iloscPrzedmiotow = pojemnik.getInt(OcenyActivity.ILOSC_PRZEDMIOTOW_KEY);
            int[] oceny = new int[iloscPrzedmiotow];
            for(int i=0;i<iloscPrzedmiotow;i++) {
                oceny[i] = pojemnik.getInt(OcenyActivity.OCENA_NR_KEY + i);
            }
            this.srednia = (float)Arrays.stream(oceny).sum()/(float)iloscPrzedmiotow;
            pokazSrednia();
        }
    }

    private void pokazSrednia() {
        if(srednia == 0) return;
        this.sredniaTv.setVisibility(View.VISIBLE);
        this.sredniaTv.setText(String.format(getString(R.string.srednia_tv), this.srednia));
        if(this.srednia >= 3) {
            this.sredniaBt.setText(R.string.srednia_sukces_bt);
        }
        else {
            this.sredniaBt.setText(R.string.srednia_powtorka_bt);
        }
        this.sredniaBt.setVisibility(View.VISIBLE);
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