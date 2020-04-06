#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long long m, x;
    while ((cin >> m >> x) && (m || x)) {

        if (x == 0 or x == 100) {
            cout << "Not found" << endl;
            continue;
        }

        long double ans = (m - 1) * 100.0;
        ans /= (100.0 - x);

        long long v = ceil(ans) - 1;

        if (v >= m)
            cout << v << endl;
        else
            cout << "Not found" << endl;
    }
    return 0;
}