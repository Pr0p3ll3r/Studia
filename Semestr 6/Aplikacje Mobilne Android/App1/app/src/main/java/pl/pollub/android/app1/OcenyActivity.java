package pl.pollub.android.app1;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.app.ActionBar;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import java.util.ArrayList;
import java.util.List;

public class OcenyActivity extends AppCompatActivity {

    private RecyclerView listaOcen;
    private List<Przedmiot> listaPrzedmiotow;
    private Button obliczSredniaBt;
    public static String ILOSC_PRZEDMIOTOW_KEY = "ILOSC_PRZEDMIOTOW";
    public static String OCENA_NR_KEY = "OCENA_NR";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_oceny);
        int liczbaPrzedmiotow = getIntent().getExtras().getInt(MainActivity.ILOSC_OCEN);
        String[] przedmioty = getResources().getStringArray(R.array.nazwy_przedmiotow_tab);
        this.listaPrzedmiotow = new ArrayList<>();
        for (int i=0;i<liczbaPrzedmiotow;i++)
        {
            this.listaPrzedmiotow.add(new Przedmiot(przedmioty[i]));
        }
        ListaOcenAdapter adapter = new ListaOcenAdapter(this.listaPrzedmiotow, this.getLayoutInflater());
        this.listaOcen = findViewById(R.id.lista_ocen_rv);
        this.listaOcen.setAdapter(adapter);
        this.listaOcen.setLayoutManager(new LinearLayoutManager(this));
        this.obliczSredniaBt = findViewById(R.id.oblicz_srednia_bt);
        this.obliczSredniaBt.setOnClickListener(v -> {
            obliczSrednia();
        });
    }

    @Override
    protected void onSaveInstanceState(@NonNull Bundle outState) {
        spakujDane(outState);
        super.onSaveInstanceState(outState);
    }

    @Override
    protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        //int iloscPrzedmiotow = savedInstanceState.getInt(this.ILOSC_PRZEDMIOTOW_KEY);
        for(int i=0;i<listaPrzedmiotow.size();i++) {
            this.listaPrzedmiotow.get(i).setOcena(savedInstanceState.getInt(this.OCENA_NR_KEY+i));
        }
    }

    private void obliczSrednia() {
        Bundle pojemnik = new Bundle();
        spakujDane(pojemnik);
        Intent intent = new Intent();
        intent.putExtras(pojemnik);
        this.setResult(RESULT_OK,intent);
        this.finish();
    }

    private void spakujDane(Bundle pojemnik) {
        int iloscPrzedmiotow = this.listaPrzedmiotow.size();
        pojemnik.putInt(this.ILOSC_PRZEDMIOTOW_KEY, iloscPrzedmiotow);
        for(int i=0;i<listaPrzedmiotow.size();i++) {
            pojemnik.putInt(this.OCENA_NR_KEY+i,this.listaPrzedmiotow.get(i).getOcena());
        }
    }
}