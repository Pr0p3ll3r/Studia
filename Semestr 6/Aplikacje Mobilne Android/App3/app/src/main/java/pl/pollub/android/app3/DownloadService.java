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
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import androidx.localbroadcastmanager.content.LocalBroadcastManager;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URL;

import javax.net.ssl.HttpsURLConnection;

public class DownloadService extends IntentService {
    private static final String AKCJA_POBIERZ_PLIK = "AKCJA_POBIERZ_PLIK";
    private static final String PARAMETR1_KEY = "ADRES";
    private static final int ID_POWIADOMIENIA = 1;
    public final static String POWIADOMIENIE = "DownloadService.powiadomienie";
    public final static String PROGRESS_INFO_KEY = "PROGRESS_INFO_KEY";
    private static final int ROZMIAR_BLOKU = 32767;
    private static final String ID_KANALU = "DownloadService.kanal";
    private NotificationManager notificationManager;
    private ProgressInfo progressInfo = new ProgressInfo();
    public DownloadService() {
        super("DownloadService");
    }

    public static void rozpocznijPobieraniePliku(Context context, String adres) {
        Intent zamiar = new Intent(context, DownloadService.class);
        zamiar.setAction(AKCJA_POBIERZ_PLIK);
        zamiar.putExtra(PARAMETR1_KEY, adres);
        context.startService(zamiar);
    }

    @Override
    protected void onHandleIntent(Intent intent) {
        this.notificationManager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
        przygotujKanalPowiadomien();
        startForeground(ID_POWIADOMIENIA, utworzPowiadomienie());
        if (this.AKCJA_POBIERZ_PLIK.equals(intent.getAction())) {
            String adresPliku = intent.getStringExtra(PARAMETR1_KEY);
            wykonajZadanie(adresPliku);
        } else {
            Log.e("DownloadService", "Nieznana akcja");
        }
    }

    private void wykonajZadanie(String adresPliku) {
        HttpsURLConnection polaczenie = null;
        FileOutputStream strumienDoPliku = null;
        try {
            URL url = new URL(adresPliku);
            polaczenie = (HttpsURLConnection) url.openConnection();
            this.progressInfo = new ProgressInfo();
            this.progressInfo.setFileSize(polaczenie.getContentLength());
            File plikRoboczy = new File(url.getFile());
            File plikWyjsciowy = new File(getBaseContext().getFilesDir().getPath() + File.separator + plikRoboczy.getName());
            if (plikWyjsciowy.exists()) {
                plikWyjsciowy.delete();
            }
            DataInputStream czytnik = new DataInputStream(polaczenie.getInputStream());
            strumienDoPliku = new FileOutputStream(plikWyjsciowy.getPath());
            byte bufor[] = new byte[ROZMIAR_BLOKU];
            int pobrano = czytnik.read(bufor, 0, ROZMIAR_BLOKU);
            Handler handler = new Handler(Looper.getMainLooper());
            this.progressInfo.setDownloadStatus(0);
            while (pobrano != -1)
            {
                strumienDoPliku.write(bufor, 0, pobrano);
                this.progressInfo.increaseDownloadBytes(pobrano);
                this.notificationManager.notify(ID_POWIADOMIENIA, utworzPowiadomienie());
                wyslijBroadcast();
                Log.d("DownloadService", "Pobrano bajtów: " + this.progressInfo.getDownloadBytes());
                pobrano = czytnik.read(bufor, 0, ROZMIAR_BLOKU);
            }
            Log.d("DownloadService","Pobrano plik");
        } catch (Exception e) {
            e.printStackTrace();
            this.progressInfo.setDownloadStatus(2);
        } finally {
            if (strumienDoPliku != null)
            {
                try {
                    strumienDoPliku.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (polaczenie != null)
            {
                polaczenie.disconnect();
            }
            this.progressInfo.setDownloadStatus(1);
        }
    }

    private void przygotujKanalPowiadomien() {
        this.notificationManager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            CharSequence name = getString(R.string.app_name);
            NotificationChannel kanal = new NotificationChannel(ID_KANALU, name, NotificationManager.IMPORTANCE_LOW);
            this.notificationManager.createNotificationChannel(kanal);
        }
    }

    private Notification utworzPowiadomienie() {
        Intent intencjaPowiadomienia = new Intent(this, MainActivity.class);
        TaskStackBuilder budowniczyStosu = TaskStackBuilder.create(this);
        budowniczyStosu.addParentStack(MainActivity.class);
        budowniczyStosu.addNextIntent(intencjaPowiadomienia);
        PendingIntent intencjaOczekujaca = budowniczyStosu.getPendingIntent(0, PendingIntent.FLAG_UPDATE_CURRENT);
        Notification.Builder budowniczyPowiadomien = new Notification.Builder(this);
        budowniczyPowiadomien.setContentTitle(getString(R.string.powiadomienie_tytul))
                .setProgress(100, this.progressInfo.progressValue(), false)
                .setContentIntent(intencjaOczekujaca)
                .setSmallIcon(R.mipmap.ic_launcher)
                .setWhen(System.currentTimeMillis())
                .setPriority(Notification.PRIORITY_HIGH);
        if (!this.progressInfo.isDownloadComplete()) {
            budowniczyPowiadomien.setOngoing(false);
        } else {
            budowniczyPowiadomien.setOngoing(true);
        }

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            budowniczyPowiadomien.setChannelId(ID_KANALU);
        }

        return budowniczyPowiadomien.build();
    }

    private void wyslijBroadcast() {
        Intent zamiar = new Intent(POWIADOMIENIE);
        zamiar.putExtra(PROGRESS_INFO_KEY, this.progressInfo);
        LocalBroadcastManager.getInstance(this).sendBroadcast(zamiar);
    }
}
