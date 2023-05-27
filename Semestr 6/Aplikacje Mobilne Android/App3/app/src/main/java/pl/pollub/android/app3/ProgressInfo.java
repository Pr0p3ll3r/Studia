package pl.pollub.android.app3;

import android.os.Parcel;
import android.os.Parcelable;

import androidx.annotation.NonNull;

public class ProgressInfo implements Parcelable {
    public final static int DOWNLOAD_START = 0;
    public final static int DOWNLOAD_END = 1;
    public final static int DOWNLOAD_ERROR = 2;
    private int downloadBytes;
    private int fileSize;
    private int downloadStatus;

    public ProgressInfo(int downloadBytes, int fileSize, int downloadStatus) {
        this.downloadBytes = downloadBytes;
        this.fileSize = fileSize;
        this.downloadStatus = downloadStatus;
    }

    public ProgressInfo() {
        this.downloadBytes = 0;
        this.fileSize = 0;
        this.downloadStatus = 1;
    }

    protected ProgressInfo(Parcel in) {
        downloadBytes = in.readInt();
        fileSize = in.readInt();
        downloadStatus = in.readInt();
    }

    public static final Creator<ProgressInfo> CREATOR = new Creator<ProgressInfo>() {
        @Override
        public ProgressInfo createFromParcel(Parcel in) {
            return new ProgressInfo(in);
        }

        @Override
        public ProgressInfo[] newArray(int size) {
            return new ProgressInfo[size];
        }
    };

    public int getDownloadBytes() {
        return downloadBytes;
    }

    public void setDownloadBytes(int downloadBytes) {
        this.downloadBytes = downloadBytes;
    }

    public int getFileSize() {
        return fileSize;
    }

    public void setFileSize(int fileSize) {
        this.fileSize = fileSize;
    }

    public int getDownloadStatus() {
        return downloadStatus;
    }

    public void setDownloadStatus(int downloadStatus) {
        this.downloadStatus = downloadStatus;
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(@NonNull Parcel dest, int flags) {
        dest.writeInt(downloadBytes);
        dest.writeInt(fileSize);
        dest.writeInt(downloadStatus);
    }

    public int progressValue() {
        return (int)(((double)this.downloadBytes/(double)this.fileSize)*100);
    }

    public Boolean isDownloadComplete() {
        return this.downloadBytes == this.fileSize;
    }

    public void increaseDownloadBytes(int bytes) {
        this.downloadBytes += bytes;
    }
}
