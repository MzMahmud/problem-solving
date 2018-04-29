/*
    LOJ 1317 - Throwing Balls into the Baskets
    Author: Moaz Mahmud
    Date  : 31 Oct,2017

    My Solution:
        n = total #balls
        p = success rate of getting a ball in any of m bucket

        Let E(i) be the expected #balls after i turns
        E(i) = E(i-1) + Expected #balls in a i-th turn;

        Finding Expected #balls in a i-th turn:
            let b(i) is expected #balls in i-th turn
            b(i) = 1*prob getting 1 ball + 2*prob getting 2 balls +...+n*prob getting n balls
                 = sum{j = 1 to n} j*prob(j)
                 = sum{j = 1 to n} j*C(n,j)*p^(j)*(1-p)^j//binomial distribution
                 = p*n*(p+1-p)^n//use (p+(1-p))^n expansion and differentiate wrt p,to get the series
                 = n*p
        So,E(i) = E(i-1) + n*p = i*n*p.//solving recurrence
        ans is simply E(k) = k*n*p;
    END :D :D
*/
#include <cstdio>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int n,m,k;
        double p;
        scanf("%d%d%d%lf",&n,&m,&k,&p);
        printf("Case %d: %.10lf\n",cn++,k*n*p);
    }
    return 0;
}
