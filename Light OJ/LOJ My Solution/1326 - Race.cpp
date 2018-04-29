/*
    1326 - Race
    Author: Moaz Mahmud
    Date  : 09 May,2017

    My Solution:
        1 2 3 4 5 ... n
        let a(n) be the answer.
        Now choose 1 from n in 1st place and rest can be a(n-1).
        Now choose 2 from n in 1st place and rest can be a(n-2).
        So the recurrence,
        a(n) = C(n,1)*a(n-1) + C(n,2)*a(n-2) + ... + C(n,n-1)*a(1) + 1;
        base case a(1) = 1;
    END :D :D
*/
#include <cstdio>
#define SIZE 1002
#define MOD 10056

using namespace std;

int nCr[SIZE][SIZE],ans[SIZE];

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdo);
    nCr[0][0] = nCr[1][0] = nCr[1][1] = 1;
    for(int i = 2;i <= 1000;i++){
        for(int j  = 0;j <= i;j++){
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
        }
    }
    ans[1] = 1;
    for(int i = 2;i <= 1000;i++){
        for(int j = 1;j < i;j++){
            ans[i] += (nCr[i][i-j]*ans[j])%MOD;
        }
        ans[i]++;
        ans[i] %= MOD;
    }

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n",cn++,ans[n]%MOD);
    }
    return 0;
}
