#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    freopen("Input.txt","rt",stdin);
    int tc,cn=1,i,j,k;
    long long int P,L,n,div[93000],count = 0;

    scanf("%d",&tc);
    while( tc-- ){
        scanf("%lld%lld",&P,&L);
        n = P-L;
        if( L>=n  ){
            count = 1;
            printf("Case %d: impossible\n",cn++);
            continue;
        }
        else{
                if( P == 1  ){
                    printf("Case %d: 1\n",cn++);
                    continue;
                }

                if(L==0)   div[0] = 1,div[1] = n,i=2;
                else       div[0] = n,i=1;

                if(n%2==0) j=2,k=1;
                else       j=3,k=2;
                for( ;j <= (int)sqrt(n);j+=k){
                    if(n%j==0){
                        if(j>L)
                            div[i++] = j;
                        if( (n/j) > L && (n/j) != j)
                            div[i++] = (n/j);
                    }
                }
                sort(div,div+i);

                printf("Case %d:",cn++);
                for(k=0;k<i;k++)
                    printf(" %lld",div[k]);
                printf("\n");
        }
    }
    return 0;
}
