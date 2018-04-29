/*
    LOJ 1038 - Race to 1 Again
    Author: Moaz Mahmud
    Date  : 31 Oct,2017

    My Solution:
        let E(n) be Expected #steps to get to 1.
        divisor set = {d(1),d(2),d(3),...,d(t)}
        t = tau(n) = #divisor of n
           E(n)  = (1/t)*(1+E(d(1))) + (1/t)*(1+E(d(2))) + ... + (1/t)*(1+E(d(t)))
        -> tE(n) = t + sum{d|n} E(d)//but n|n and thats we want to find
        -> tE(n) = t + sum{d|n and d != n} E(d) + E(n)
        -> (t-1)E(n) = t + sum{d|n and d != n}
        -> E(n) = (t + sum{d|n and d != n})/(t-1);//base case E(1) = 0.0
        Now as for all d|n, d <= n and E(d) is overlapping
        it is solved by bottom-up DP.

    END :D :D
*/

#include <cstdio>
#define MAXN 100005

using namespace std;

double E[MAXN];

double EofDivisiors(int n){
    double sum = 0.0;
    int tau = 2;
    for(int i = 2;i*i <= n;i++){
        if(!(n%i)){
            sum += E[i];
            tau++;
            if((n/i) != i){
                sum += E[n/i];
                tau++;
            }
        }
    }
    return E[n] = (tau + sum)/(tau - 1);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    E[1] = .0;//base case
    for(int i = 2;i < MAXN-2;i++)
        E[i] = EofDivisiors(i);

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        printf("Case %d: %.10lf\n",cn++,E[n]);
    }
    return 0;
}
