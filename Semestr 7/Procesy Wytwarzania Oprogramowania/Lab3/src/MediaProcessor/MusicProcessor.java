package MediaProcessor;

public interface MusicProcessor {
    Mp3 loadMusicFile(File f);
    void saveMusicFile(File f);
    Mp3 convertToMp3(Wave wave);
    Mp3 extractFromAvi(Avi avi);
    Mp3 extractFromMpeg(Mpeg mpeg);
    void addAuthor(MediaFile mf);
}
