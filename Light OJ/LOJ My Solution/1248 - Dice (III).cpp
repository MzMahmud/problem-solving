/*
    LOJ 1248 - Dice (III)
    Author: Moaz Mahmud
    Date  : 31 Oct,2017

    My Solution:
        Let E(x) be the expected #moves to see x-th different phases.
        n = Total #phases.
        Finding E(x + 1):
            Let p = probability of seeing an already seen phase = x/n;
            after 1 move of E(x),1*(prob of seeing a new phase) = 1*(1 - p);
            after 2 move of E(x),2*(prob 1st move fails)*(prob of seeing a new phase) = 2*p*(1 - p);
            after 3 move of E(x),3*(prob 1st and 2nd moves fail)*(prob of seeing a new phase) = 3*p*p*(1 - p);
            goes to infinity.

        So,E(x + 1) = E(x) + sum{k = 1 to inf} k*p^(k-1)*(1-p)
                    = E(x) + (1 - p) sum{k = 1 to inf} k*p^(k-1)//Infinite series of (1-p)^(-2)
                    = E(x) + (1 - p) (1 - p)^(-2)
                    = E(x) + (1 - p)^(-1)
                    = E(x) + 1/(1 - p)
        base,E(1) = seeing 1st new phase = 1.
    END :D :D
*/

#include <cstdio>

using namespace std;

int n;

double E(int x){
    if(x == 1) return 1.0;
    double p = (x-1)/(n*1.0);
    return E(x-1) + (1/(1-p));
}

int main(){
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d",&n);
        printf("Case %d: %.10lf\n",cn++,E(n));
    }
    return 0;
}
