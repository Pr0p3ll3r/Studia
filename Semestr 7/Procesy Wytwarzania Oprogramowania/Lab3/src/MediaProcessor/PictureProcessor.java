package MediaProcessor;

public interface PictureProcessor {
    Jpeg loadPicture(File f);
    void savePicture(File f);
    Jpeg addAuthorToPicture(Jpeg jpeg);
}
