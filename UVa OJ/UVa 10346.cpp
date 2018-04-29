#include <bits/stdc++.h>
using namespace std;
long long k;
long long cig(long long c,long long b){
    if((c+b) < k) return c;
    return c + cig((c+b)/k,((c+b)%k));
}
int main(){
    long long n;
    while(scanf("%lld%lld",&n,&k) == 2)
        cout << cig(n,0) << endl;
    return 0;
}
