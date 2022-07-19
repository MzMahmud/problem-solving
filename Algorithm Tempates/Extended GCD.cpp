#include <bits/stdc++.h>

using namespace std;

// With Structured Binding since C++17
// a x + b y = gcd(a, b)
// usage: const auto [x, y, gcd] = egcd(b, a % b);
tuple<int, int, int> egcd(int a, int b) {
    if (b == 0) {
        return {1, 0, a};
    }
    const auto [x, y, gcd] = egcd(b, a % b);
    return {y, x - (a / b) * y, gcd};
}

int egcd(int a, int b, int &x, int &y) {
    if (!a) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = egcd(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main() {
    int a = 240, b = 46;
    {
        int x, y, gcd;
        gcd = egcd(a, b, x, y);
        printf("%d(%d) + %d(%d) = %d = gcd(%d, %d) = %d\n", a, x, b, y, a * x + b * y, a,
               b, gcd);
    }

    {
        const auto [x, y, gcd] = egcd(a, b);
        printf("%d(%d) + %d(%d) = %d = gcd(%d, %d) = %d\n", a, x, b, y, a * x + b * y, a,
               b, gcd);
    }
}
