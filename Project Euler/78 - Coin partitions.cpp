#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;

int partition(int n) {
    vector<int> ways(n + 1, 0);
    ways[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int num = i; num <= n; num++)
            ways[num] = (ways[num] + ways[num - i]) % MOD;

    for (int i = 1; i <= n; i++)
        if (!ways[i])
            cout << i << endl;

    return ways[n] % MOD;
}

int main(int argc, char const *argv[]) {
    cout << partition(100000) << endl;
    return 0;
}

// 	55374
// took fairl long time :3