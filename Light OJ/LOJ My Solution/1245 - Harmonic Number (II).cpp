/*
    //LOJ 1245 - Harmonic Number (II)
    Author: Moaz Mahmud
    Date  : 14 May,2017

    My Solution:
        Observation leads to a O(sqrt(n)) algo.
        for i = 1 to n
            a = floor(n/(i+1));
            b = floor(n/i);
            from a to b the floor would be i;
    END
*/
#include <cstdio>
#include <cmath>

using namespace std;

long long solve(long long n){
    long long ans = 0,limit = sqrt(n*1.0);
    for(long long i = 1;i <= limit;i++){
        long long a,b;
        a = (n/(i+1)) + 1;
        b = (n/i);
        if(a != i) ans = ans + b + (b-a+1)*i;
        else       ans = ans + b;
    }
    return ans;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdo);
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        long long n;
        scanf("%lld", &n);
        printf("Case %d: %lld\n",cn++,solve(n));
    }
    return 0;
}

