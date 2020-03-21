/*    LOJ 1231 - Coin Change (I)
    Author: Moaz Mahmud
    Date  : 21 Mar,2020

    My Solution:
        Simple coin change
    END :D :D
*/

#include <cstdio>
#include <cstring>

using namespace std;

#define MAXK 1003
#define MAXN 53
#define MOD 100000007

int dp[MAXK][MAXN];
int coin[MAXN], coin_count[MAXN];

int n, k;

int coin_change_way(int amount, int index) {
    if (index == n) {
        if (amount == 0)
            return 1;
        else
            return 0;
    }

    if (dp[amount][index] < 0) {
        int &way = dp[amount][index];
        way      = 0;
        for (int i = 0; i <= coin_count[index]; i++) {
            int new_amount = amount - i * coin[index];
            if (new_amount >= 0)
                way = (way + coin_change_way(new_amount, index + 1)) %
                      MOD;
            else
                break;
        }
    }

    return dp[amount][index];
}

int main() {
    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &coin[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &coin_count[i]);

        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", cn++, coin_change_way(k, 0));
    }
    return 0;
}