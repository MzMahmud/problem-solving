#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int m;

bool compare(int a, int b) {
    int a_m = a % m;
    int b_m = b % m;
    if (a_m != b_m)
        return a_m < b_m;

    a_m = a & 1;
    b_m = b & 1;
    if (a_m ^ b_m) // one even,one odd
        return a_m > b_m;

    if (a_m || b_m) // both odd
        return a > b;

    return a < b;
}

int main() {
    int n;
    while (cin >> n >> m && (n || m)) {
        vector<int> nums(n);
        for (auto &num : nums)
            cin >> num;

        sort(nums.begin(), nums.end(), compare);

        cout << n << " " << m << endl;
        for_each(nums.begin(), nums.end(), [](int n) { cout << n << endl; });
    }
    cout << 0 << " " << 0 << endl;
    return 0;
}