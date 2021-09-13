#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x0, y0;
    bool all_x_same = true, all_y_same = true;
    cin >> n;
    cin >> x0 >> y0;
    while (--n) {
        int x, y;
        cin >> x >> y;
        all_x_same &= (x0 == x);
        all_y_same &= (y0 == y);
    }
    cout << ((all_x_same || all_y_same) ? "YES" : "NO") << endl;
    return 0;
}
