#include <iostream>
#include <vector>

using namespace std;

enum SearchType { FIRST_OCCURRENCE, LAST_OCCURRENCE, ANY_OCCURRENCE };

template <typename T>
int binary_search(const vector<T> &a, const T &key,
                  SearchType search_type = ANY_OCCURRENCE) {
    int lo = 0;
    int hi = a.size() - 1;
    int mid;
    int found_index = -1;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (a[mid] == key) {
            found_index = mid;
            if (search_type == ANY_OCCURRENCE)
                return found_index;
            else if (search_type == FIRST_OCCURRENCE)
                hi = mid - 1;
            else if (search_type == LAST_OCCURRENCE)
                lo = mid + 1;
        } else if (a[mid] < key) {
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

    int first_occurrence = binary_search(a, key, FIRST_OCCURRENCE);
    int last_occurrence  = binary_search(a, key, LAST_OCCURRENCE);
    int count            = (first_occurrence < 0 && last_occurrence < 0)
                               ? 0
                               : last_occurrence - first_occurrence + 1;

    cout << first_occurrence << " " << last_occurrence << " " << count << endl;
    return 0;
}
