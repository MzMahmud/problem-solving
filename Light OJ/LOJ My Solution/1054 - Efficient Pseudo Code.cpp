#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
#define mod 1000000007
#define maxn 65540

int vis[maxn];
int prime[maxn];
long long num[maxn/10];
int n_prime=0;

void Prime()
{
    memset(vis,1,sizeof(vis));
    vis[1]=vis[0]=0;
    for(int i=2;i<maxn;i++)
        if(vis[i]){
            prime[++n_prime]=i;
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=0;
        }
}
long long Pow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b & 1){
            b--;
            ans=(ans*a)%mod;
        }
        else{
            b/=2;
            a=(a*a)%mod;
        }
    }
    return ans;
}

long long sum(long long p,long long n)
{
    if(n==0)
        return 1;
    if(n==1)
        return p+1;
    if(n&1)
        return (sum(p,n/2)*((1+Pow(p,n/2+1))%mod))%mod;

    else
        return ((sum(p,n/2-1)*((1+Pow(p,n/2))%mod))%mod+Pow(p,n))%mod;
}

int main()
{
    Prime();
    //freopen("Input.txt","rt",stdin);
    int tc,cn = 1;
    scanf("%d",&tc);
    while( tc-- ){
        int m,n;
        scanf("%d%d",&n,&m);
        memset(num,0,sizeof(num));
        for(int i=1;i<=n_prime&&prime[i]<=n;i++){
            if(n%prime[i]==0){
                while(n%prime[i]==0){
                    n/=prime[i];
                    num[i]+=m;
                }
            }
        }
        long long ans=1;
        if(n!=1)
            ans=sum(n,m);

        long long tmp;
        for(int i=1;i<=n_prime;i++){
            tmp=sum(prime[i],num[i]);
            ans=(ans*tmp)%mod;
        }
        printf("Case %d: ",cn++);
        printf("%lld\n",ans);
    }
    return 0;
}
