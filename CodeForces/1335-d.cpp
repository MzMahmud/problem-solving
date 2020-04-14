#include <bits/stdc++.h>

using namespace std;

void change(char &c) {
    if (c == '9')
        c = '1';
    else
        c++;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        string row;
        int a[9] = {0, 3, 6, 1, 4, 7, 5, 2, 8};
        for (int i = 0; i < 9; i++){
            cin >> row;
            change(row[a[i]]);
            cout << row << endl;
        }
    }
    return 0;
}