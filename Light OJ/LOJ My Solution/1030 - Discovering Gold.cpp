/*
    LOJ 1030 - Discovering Gold
    Author: Moaz Mahmud
    Date  : 31 Oct,2017

    My Solution:
        let expected gold of n-th cell is E(n)
        reachable cell = {c(1),c(2),..,c(r)}
        clearly,0 <= r <= 6 and (n-r) < 6?(n-r):6

        E(i) = (1/6)*(sum{for all reachable cell c} gold(i) + E(c))
                + ((6-r)/6)*E(i)
        //this is because for all non-reachable back to the current cell
        by simplifying,
        E(i) = (r*gold(i) + sum{for all reachable cell} E(c))/r
        Base Case, E(n) = gold(n);
        ans is E(1).
        Its overlapping so used DP from n to .

    END :D :D
*/

#include <cstdio>
#define MAXN 120

using namespace std;

double E[MAXN];
int gold[MAXN];

inline int rechable(int i,int n){return (n-i)< 6?(n-i):6;}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            scanf("%d", &gold[i]);
        }
        E[n] = gold[n]*1.0;
        for(int i = n-1;i >= 1;i--){
            int r  = rechable(i,n);
            double next = 0.0;
            for(int j = 1;j <= r;j++) next += E[i+j];
            E[i] = (r*gold[i] + next)/r;
        }
        printf("Case %d: %lf\n",cn++,E[1]);
    }
    return 0;
}
