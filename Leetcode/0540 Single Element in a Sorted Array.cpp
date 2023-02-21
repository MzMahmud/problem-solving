#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int singleNonDuplicate(const vector<int> &a) {
        int lo = 0, hi = a.size() - 1;
        int mid = lo + (hi - lo) / 2;
        while (lo < hi) {
            if (a[mid - 1] != a[mid] and a[mid] != a[mid + 1]) {
                break;
            }
            pair<int, int> left, right;
            if (a[mid - 1] == a[mid]) {
                left = {lo, mid};
                right = {mid + 1, hi};
            } else {
                left = {lo, mid - 1};
                right = {mid, hi};
            }
            tie(lo, hi) = isOddSized(left) ? left : right;
            mid = lo + (hi - lo) / 2;
        }
        return a[mid];
    }

    inline bool isOddSized(const pair<int, int> &interval) {
        return (interval.second - interval.first + 1) & 1;
    }
};