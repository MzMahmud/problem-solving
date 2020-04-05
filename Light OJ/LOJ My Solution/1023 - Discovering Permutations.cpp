/*
    LOJ 1023 - Discovering Permutations
    Author : Moaz Mahmud
    Date   : 05 Apr,2020
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void print_perm(int n, int &k, string perm = "",
                unordered_set<char> used = {}) {

    if (k == 0) {
        return;
    }
    if (used.size() == n) {
        k--;
        cout << perm << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used.find('A' + i) == used.end()) {
            used.insert('A' + i);
            string new_perm = perm + string(1, (char)('A' + i));
            print_perm(n, k, new_perm, used);
            used.erase('A' + i);
        }
    }
}

int main() {
    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);

        string chars(n, 'A');
        for (int i = 1; i < n; i++)
            chars[i] = chars[i - 1] + 1;

        printf("Case %d:\n", cn++);
        // do {
        //     printf("%s\n", chars.c_str());
        //     k--;
        // } while (k and next_permutation(chars.begin(), chars.end()));
        print_perm(n, k);
    }
    return 0;
}
