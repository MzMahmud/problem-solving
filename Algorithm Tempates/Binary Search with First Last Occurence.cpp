#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

enum SearchType { FIRST_OCCURENCE, LAST_OCCURENCE, ANY_OCCURENCE };

template <typename T>
int binary_search(const vector<T> &a, T key, SearchType search_type = ANY_OCCURENCE) {
    int lo = 0;
    int hi = a.size() - 1;
    int mid;
    int found_index = -1;
    while (lo <= hi) {
        mid                 = lo + (hi - lo) / 2;
        const int &mid_elem = a[mid];
        if (mid_elem == key) {
            found_index = mid;
            if (search_type == ANY_OCCURENCE)
                return found_index;
            else if (search_type == FIRST_OCCURENCE)
                hi = mid - 1;
            else if (search_type == LAST_OCCURENCE)
                lo = mid + 1;
        }
        if (mid_elem < key) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return found_index;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a)
        cin >> ai;
    int key;
    cin >> key;
    int first_occ = binary_search(a, key, FIRST_OCCURENCE);
    int last_occ  = binary_search(a, key, LAST_OCCURENCE);
    int count     = first_occ < 0 && last_occ < 0 ? 0 : last_occ - first_occ + 1;
    cout << first_occ << " " << last_occ << " " << count << endl;
    return 0;
}
