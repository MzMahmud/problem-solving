#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main() {
    // freopen("in", "r", stdin);

    int n;
    scanf("%d", &n);

    int x = -1;
    vector<int> nums(n);
    map<int, int> count;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        nums[i] = abs(num);
        count[nums[i]]++;
        x = max(nums[i], x);
    }

    for (int i = 0; i < n; i++) {
        int &num = nums[i];
        if (count[num] == 1) {
            if (!(x % num))
                num = -1;
        } else if (count[num] == 2) {
            count[num] = 0;
            num        = -1;
        }
    }
    int y = -1;
    for (int i = 0; i < n; i++) {
        y = max(nums[i], y);
    }

    printf("%d %d\n", x, y);
    return 0;
}