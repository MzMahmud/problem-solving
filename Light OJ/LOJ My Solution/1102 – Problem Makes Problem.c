#include <stdio.h>
#define MOD 1000000007
#define SIZE 2000004

typedef long long int ll;
ll bigMod(ll ,ll ,ll );

ll fact[SIZE],modinv[SIZE] = {0},j,ans;

int main()
{
    //freopen("Input.txt","rt",stdin);
    //freopen("Output.txt","wt",stdout);
    int tc,cn=1,n,r,i;

    //Pre-calculates Factorials
    fact[0] = modinv[0] = 1;
    for(i=1;i<SIZE;i++)
        fact[i] = (fact[i-1]*i) % MOD;

    scanf("%d",&tc);
    while( tc-- ){
          scanf("%d%d",&n,&r);
          r = r-1;
          n = n+r;

          if( modinv[n] == 0)
              modinv[n] = bigMod(fact[n],MOD-2,MOD);
          if( modinv[r] == 0)
              modinv[r] = bigMod(fact[r],MOD-2,MOD);
          if( modinv[n-r] == 0)
              modinv[n-r] = bigMod(fact[n-r],MOD-2,MOD);

          ans = ( fact[n]*modinv[r] ) % MOD;
          ans = ( ans*modinv[n-r] ) % MOD;
          printf("Case %d: %lld\n",cn++,ans);
    }
    return 0;
}

ll bigMod(ll a,ll b,ll M)
{
    if ( b == 0 )  return (1 % M);
    int x = bigMod( a , b / 2 , M) ;
    x = ( (x%M) * (x%M) ) % M;
    if ( b % 2 == 1 ) x = (x*a) % M;
    return x ;
}
