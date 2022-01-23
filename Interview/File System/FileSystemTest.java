import java.util.Arrays;
import java.util.List;

public class FileSystemTest {
    public static void main(String[] args) {
        List<String> fileNames = Arrays.asList(
                "config.json",
                "/urs/bin/bash",
                "/urs/bin/mysql",
                "/urs/mzmahmud/home",
                "/urs/mzmahmud/home/code/main.cpp",
                "/urs/mzmahmud/home/code/main.py",
                "/urs/mzmahmud/home/music/arnob/one.mp3",
                "/urs/mzmahmud/home/music/arnob/two.mp3",
                "/urs/mzmahmud/home/music/arnob/three.mp3",
                "/urs/mzmahmud/home/movies/bangla/one.mp4",
                "/urs/mzmahmud/home/movies/bangla/two.mkv",
                "/urs/mzmahmud/home/movies/english/one.flv",
                "/urs/local/bin/mysql",
                "/urs/local/bin/mysql"
        );

        FileSystem fileSystem = new FileSystem();
        fileNames.forEach(fileName -> System.out.println(fileName + " idAdded=" + fileSystem.addFile(fileName)));
        
        System.out.println("\n\n\nFile System Tree:");
        fileSystem.printFilesTree();
    }
}
