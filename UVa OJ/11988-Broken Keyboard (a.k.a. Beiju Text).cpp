#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main() {
    string line;
    while (cin >> line) {
        list<char> out;
        bool home = false;
        int front_chars = 0;
        for (auto c : line) {
            if (c == '[') {
                home = true;
                front_chars = 0;
            } else if (c == ']') {
                home = false;
                front_chars = 0;
            } else if (home) {
                auto it = out.begin();
                advance(it, front_chars);
                out.insert(it, c);
                front_chars++;
            } else {
                out.push_back(c);
            }
        }
        cout << string(out.begin(), out.end()) << endl;
    }
    return 0;
}