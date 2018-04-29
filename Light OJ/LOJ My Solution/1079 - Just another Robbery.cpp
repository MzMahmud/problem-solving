/*
    LOJ 1079 - Just another Robbery
    Author: Moaz Mahmud
    Date  : 27 Nov,2017

    My Solution:
        This problem is like a 0-1 Knapsack Problem
        p is the probability of getting caught.
        money[i],prob[i] is the i-th money and probability.
        probability of getting caught in any one is,
        1 - (probability of not getting caught) = 1 - prod_{for all i} prod[i].
        let ans(i,prod) be the function that gives maximum money from item
        1 to i with all not getting caught probability.

        Now if (1 - prod*(1-prob[i])) >= p the current item cant be taken so ans(i-1,prod)
        else ans(i,prod) = MAX( money[i] + ans(i-1,prob[i]*prob) , ans(i-1,prob) )
        base case:: ans(0,anything) = 0.

        But as this involves fractions this is hard to implement DP.
        Got TLE in a try though :V.
        so the trick is to run DP on total money.
        as money[i] <= 100 and n <= 100. Total money <= 10000.
        So for each bank a search is run to optimally contribute to the total money.

    END :D :D
*/


#include <cstdio>
#define MAXN 103
#define MAXM 10003
#define MAX(a,b) (a > b? a:b)

using namespace std;

double dp[MAXM],pi[MAXN];
int money[MAXN];

int main(){
    freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int n,m = 0;
        double p;
        scanf("%lf%d",&p,&n);
        p = 1.0 - p;//prob of not getting caught
        for(int i = 0;i < n;i++){
            scanf("%d%lf",&money[i],&pi[i]);
            pi[i] = 1 - pi[i];//prob of not getting caught
            m += money[i];//total money
        }
        for(int i = 0;i <= m;i++) dp[i] = 0;
        dp[0] = 1.0;
        for(int i = 0;i < n;i++){
            for(int j = m;j >= money[i];j--){
                if((dp[j-money[i]]*pi[i]) < p) continue;
                dp[j] = MAX(dp[j],dp[j-money[i]]*pi[i]);
            }
        }
        int ans = 0;
        for(int i = m;i >= 0;i--) if(dp[i] >= p){ans = i;break;}
        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}
