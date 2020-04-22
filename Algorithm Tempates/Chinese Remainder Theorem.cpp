#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

typedef long long i64;

i64 bigMod(i64 a,i64 b,i64 M){
    if (!b)  return (1%M);
    int x = bigMod(a,b/2,M);
    x = ((x%M)*(x%M))% M;
    if(b&1)//is same as b%2 == 1
        x = (x*a)%M;
    return x;
}

/*
    Algorithm:
        https://brilliant.org/wiki/chinese-remainder-theorem/
    Use:
        Solving linear system of congruence
    Input:
        Global:
        * set of remainder,a[]
        * set of modulo,p[]
        Argument:
        * size of a[],p[]
        * reference of final modulo
    Output:
        * final modulo via reference
        * common solution
    Note:
        * Will only work for prime p[].
        * to work for any set of pairwise co-prime,mod inverse must be found by Extended GCD
 */

i64 a[MAXN],p[MAXN];
i64 chineseRemainder(int n,i64 &mod){
    mod = 1;
    i64 x = 0;
    for(int i = 0;i < n;i++) mod *= p[i];
    for(int i = 0;i < n;i++){
        i64 y,z,k;
        y = mod/p[i];
        z = bigMod(y,p[i]-2,p[i]);
        //this is to find modular inverse.
        //by Fermat's Theorem.If p[i] is not prime modular inverse have to be found by Extended GCD
        k = a[i]*z;if(k >= mod) k %= mod;
        k = k * y; if(k >= mod) k %= mod;
        x = x + k; if(x >= mod) x %= mod;
        //if checks,as remainder finding is costly operation.Done when needed.
    }
    return (x < mod) ? x : (x % mod);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    i64 mod;
    a[0] = 1;a[1] = 4;a[2] = 6;
    p[0] = 3;p[1] = 5;p[2] = 7;
    cout << chineseRemainder(3,mod) << endl;
    cout << mod << endl;

    return 0;
}
