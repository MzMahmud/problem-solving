#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define SIZE 5000003
long long phi[SIZE];
bool mark[SIZE];
void sievePhi(int n)
{
    int i,j;

    phi[1]  = 1;
    mark[1] = 1;

    for(i = 2;i <= n;i++) phi[i] = i;

    for(i = 2;i <= n;i += 2){
        phi[i] = i/2;
        if(i != 2) mark[i] = 1;
    }

    for(i = 3;i <= n; i+= 2){
        if( !mark[i] ){
            phi[i] = i - 1;
            for(j = 2*i; j <= n;j += i){
                mark[j] = 1;
                 phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

int main()
{
    sievePhi(5000002);
    int i,T,cn = 1,a,b;
    for(i = 2;i <= 5000002;i++){
        phi[i] = phi[i-1] + (phi[i]*phi[i]);
    }


    scanf("%d",&T);
    while( T-- ){
        scanf("%d%d",&a,&b);
        printf("Case %d: %llu\n",cn++,phi[b]-phi[a-1]);
    }
    return 0;
}
