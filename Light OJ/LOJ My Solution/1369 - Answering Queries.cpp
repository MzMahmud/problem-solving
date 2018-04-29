/*
    //LOJ 	1369 - Answering Queries
    Author: Moaz Mahmud
    Date  : 14 May,2017

    My Solution:
        Just an observation:
            for any i = 0 to n-1 th number in the array
            it appears exactly i time as negative in A[i] - A[j]
        So sum = sum i = 0 to n - 1 a[i]*(n-1-i) - a[i]*i
               = sum i = 0 to n - 1 a[i]*(n-1-2i)
        if A[x] is changed remove a[x]*(n-1-2x) where a[x] is old one
        and add a[x]*(n-1-2x) where a[x] is old one.
    END
*/
#include <cstdio>
#define SIZE 100005

typedef long long int ll;

using namespace std;

ll A[SIZE];

int main() {
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        ll sum = 0;
        int n,q,N;
        scanf("%d%d", &n,&q);
        N = n-1;
        for(int i = 0;i < n;i++){
            scanf("%lld", &A[i]);
            sum = sum + A[i]*(N - 2*i);
        }

        printf("Case %d:\n",cn++);

        for(int i = 0;i < q;i++){
            int a,b,c;
            scanf("%d", &a);
            if(a == 0){
                scanf("%d%d", &b,&c);
                sum = sum + A[b]*(2*b - N);
                A[b] = c;
                sum = sum + A[b]*(N - 2*b);
            }else printf("%lld\n", sum);
        }
    }
    return 0;
}
