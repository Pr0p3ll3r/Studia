package pl.pollub.android.app3;

import android.app.IntentService;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.TaskStackBuilder;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Environment;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.widget.TextView;

import com.google.android.material.slider.Slider;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;

import javax.net.ssl.HttpsURLConnection;

public class DownloadService extends IntentService {

    private static final String AKCJA_POBIERZ_PLIK = "AKCJA_POBIERZ_PLIK";

    private static final String PARAMETR1_KEY = "PARAMETR1_KEY";

    private static final int ID_POWIADOMIENIA = 1;
    private static final int ROZMIAR_BLOKU = 32767;
    private NotificationManager notificationManager;

    private Slider pobieranieSlider;

    public DownloadService() {
        super("DownloadService");
    }

    public static void rozpocznijPobieraniePliku(Context context, String parametr) {
        Intent zamiar = new Intent(context, DownloadService.class);
        zamiar.setAction(AKCJA_POBIERZ_PLIK);
        zamiar.putExtra(PARAMETR1_KEY, parametr);
        context.startService(zamiar);
    }

    @Override
    protected void onHandleIntent(Intent intent) {
        if (this.AKCJA_POBIERZ_PLIK.equals(intent.getAction())) {
            String adresPliku = intent.getStringExtra(PARAMETR1_KEY);
            HttpsURLConnection polaczenie = null;
            InputStream strumienZSieci = null;
            FileOutputStream strumienDoPliku = null;
            try {
                URL url = new URL(adresPliku);
                polaczenie = (HttpsURLConnection) url.openConnection();
                File plikRoboczy = new File(url.getFile());
                File plikWyjsciowy = new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS) +
                        File.separator + plikRoboczy.getName());
                if (plikWyjsciowy.exists()) {
                    plikWyjsciowy.delete();
                }
                DataInputStream czytnik = new DataInputStream(polaczenie.getInputStream());
                strumienDoPliku = new FileOutputStream(plikWyjsciowy.getPath());
                byte bufor[] = new byte[ROZMIAR_BLOKU];
                int pobrano = czytnik.read(bufor, 0, ROZMIAR_BLOKU);
                int pobranychBajtow = pobrano;
                Handler handler = new Handler(Looper.getMainLooper());
                while (pobrano != -1)
                {
                    strumienDoPliku.write(bufor, 0, pobrano);
                    pobranychBajtow += pobrano;
                    Log.d("DownloadService", "Pobrano bajtów: " + pobranychBajtow);
                    pobrano = czytnik.read(bufor, 0, ROZMIAR_BLOKU);
                }
                Log.d("DownloadService","Pobrano plik");
            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                if (strumienZSieci != null)
                {
                    try
                    {
                        strumienZSieci.close();
                    } catch (IOException e)
                    {
                        e.printStackTrace();
                    }
                }
                if (polaczenie != null)
                {
                    polaczenie.disconnect();
                }
            }
        }
    }
}
