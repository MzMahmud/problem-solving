#include<bits/stdc++.h>

#define ABS(a) ( (a) < 0? -(a) : (a) )

using namespace std;

int main() {
    int T, cn = 1, n, a;
    unordered_map<int,int> abs_map;

    scanf("%d", &T);
    while(T--) {
        abs_map.clear();

        scanf("%d", &n);
        while(n--) {
            scanf("%d", &a);
            abs_map[ABS(a)] = a;
        }

        long long shadow_sum = 0;
        for(const auto &abs_ai_pair : abs_map)
            shadow_sum += abs_ai_pair.second;

        printf("Case %d: %lld\n", cn++, shadow_sum);
    }
    return 0;
}
