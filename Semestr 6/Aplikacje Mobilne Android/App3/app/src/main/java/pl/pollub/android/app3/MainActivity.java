package pl.pollub.android.app3;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.localbroadcastmanager.content.LocalBroadcastManager;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.net.URL;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import javax.net.ssl.HttpsURLConnection;

public class MainActivity extends AppCompatActivity {

    private Button pobierzInfoBt;
    private Button pobierzPlikBt;
    private TextView adresTv;
    private TextView rozmiarPlikuTv;
    private TextView typPlikuTv;
    private ProgressBar postepPb;
    private TextView pobranoBajtowTv;
    private ProgressInfo progressInfo;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        this.pobierzInfoBt = findViewById(R.id.download_information_bt);
        this.adresTv = findViewById(R.id.address_et);
        this.rozmiarPlikuTv = findViewById(R.id.file_size_value_tv);
        this.typPlikuTv = findViewById(R.id.file_type_value_tv);
        this.pobierzInfoBt.setOnClickListener(view -> pobierzInfo());
        this.pobierzPlikBt = findViewById(R.id.download_file_bt);
        this.pobierzPlikBt.setOnClickListener((view -> pobierzPlik()));
        this.postepPb = findViewById(R.id.download_pb);
        this.pobranoBajtowTv = findViewById(R.id.downloaded_value_tv);
    }
    private void pobierzPlik() {
        pobierzInfo();
        DownloadService.rozpocznijPobieraniePliku(this, this.adresTv.getText().toString());
    }
    private void pobierzInfo() {
        ExecutorService executorService = Executors.newSingleThreadExecutor();
        executorService.execute(() -> {
            final FileInfo fileInfo = pobierzInfo(this.adresTv.getText().toString());
            Handler handler = new Handler(Looper.getMainLooper());
            handler.post(() -> {
                this.typPlikuTv.setText(fileInfo.getFileType());
                this.rozmiarPlikuTv.setText(Integer.toString(fileInfo.fileSize));
            });
        });
    }
    private FileInfo pobierzInfo(String adres) {
        HttpsURLConnection polaczenie = null;
        final FileInfo fileInfo = new FileInfo();
        try {
            URL url = new URL(adres);
            polaczenie = (HttpsURLConnection) url.openConnection();
            polaczenie.setRequestMethod("GET");
            fileInfo.setFileSize(polaczenie.getContentLength());
            fileInfo.setFileType(polaczenie.getContentType());
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(polaczenie != null){
                polaczenie.disconnect();
            }
        }
        return fileInfo;
    }
    class FileInfo {
        private String fileType;
        private int fileSize;

        public String getFileType() {
            return fileType;
        }

        public void setFileType(String fileType) {
            this.fileType = fileType;
        }

        public int getFileSize() {
            return fileSize;
        }

        public void setFileSize(int fileSize) {
            this.fileSize = fileSize;
        }
    }

    private BroadcastReceiver broadcastReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            progressInfo = intent.getParcelableExtra(DownloadService.PROGRESS_INFO_KEY);
            updateUIFromProgressInfo(progressInfo);
            pobierzInfo();
        }
    };

    @Override
    protected void onResume() {
        super.onResume();
        LocalBroadcastManager.getInstance(this).registerReceiver(this.broadcastReceiver, new IntentFilter(DownloadService.POWIADOMIENIE));
        updateUIFromProgressInfo(progressInfo);
    }

    @Override
    protected void onPause() {
        super.onPause();
        LocalBroadcastManager.getInstance(this).unregisterReceiver(this.broadcastReceiver);
    }

    @Override
    protected void onSaveInstanceState(@NonNull Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putParcelable(DownloadService.PROGRESS_INFO_KEY, progressInfo);
    }

    @Override
    protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        progressInfo = savedInstanceState.getParcelable(DownloadService.PROGRESS_INFO_KEY);
        updateUIFromProgressInfo(progressInfo);
        pobierzInfo();
    }

    private void updateUIFromProgressInfo(ProgressInfo progressInfo) {
        if (progressInfo != null) {
            MainActivity.this.postepPb.setProgress(progressInfo.progressValue());
            MainActivity.this.pobranoBajtowTv.setText(Integer.toString(progressInfo.getDownloadBytes()));
            if (progressInfo.isDownloadComplete()) {
                MainActivity.this.pobierzPlikBt.setClickable(true);
            } else {
                MainActivity.this.pobierzPlikBt.setClickable(false);
            }
        }
    }
}