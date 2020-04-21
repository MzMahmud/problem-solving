/*
    LOJ 1076 - Get the Containers
    Author: Moaz Mahmud
    Date  : 21 Apr,2020

    My Solution:
        if 2,3,5,10 works then 10,10,10,10 also works.
        also if 10,10,10,10 works, 11,11,11,11 ; 12,12,12,12,...
        also works.
        as we are asked to minimize the maximum size.

        so binary search on range
        lo = 0
        hi = sum(ci) (at worst case) = M
        if mid is valid:
            everything above mid is valid
        if mid not valid:
            everything below mid is invalid

        comolexity: O(c*lg(M))

    END :D :D
*/

#include <cstdio>
#include <vector>

using std::vector;

bool is_valid(int cap, int m, const vector<int> &vas) {
    int i = 0;
    int cont = 0, cont_i = 1;
    for (int vcap : vas) {
        if (cap < vcap)
            return false;

        if ((cont + vcap) > cap) {
            cont_i++;
            cont = vcap;
        } else
            cont += vcap;

        if (cont_i > m)
            return false;
    }
    return cont_i <= m;
}

int binary_search(int m, const vector<int> &vas) {
    int lo = 0, hi = 1000000002, mid;
    while (lo < hi) {
        mid = (hi + lo) / 2;
        if (is_valid(mid, m, vas))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);

        vector<int> vas(n);
        for (int &v : vas)
            scanf("%d", &v);

        printf("Case %d: %d\n", cn++, binary_search(m, vas));
    }
    return 0;
}