package MediaProcessor;

public interface VideoProcessor {
    Mpeg loadVideoFile(File f);
    void saveVideoFile(File f);
    Avi convertToAvi(Mpeg mpeg);
    void addAuthor(MediaFile mf);
}
