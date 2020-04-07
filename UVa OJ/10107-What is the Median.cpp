#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string seq;
    while (cin >> seq) {
        if (seq == "#")
            break;
        cout << seq << endl;
    }
    return 0;
}