#include "file_system.cpp"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    FileSystem file_system;
    vector<string> file_names = {"config/config.json",
                                 "config/config.yaml",
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
                                 "/urs/local/bin/mysql"};

    for (const auto &file_name : file_names) {
        cout << file_name << " is_added=" << boolalpha << file_system.add_file(file_name)
             << endl;
    }
    cout << "\n\nFile System Tree:\n";
    file_system.print_as_tree();
    return 0;
}
