#include <stdio.h>

int main()
{
    int T,cn = 1,n,p,q,i,j,ans,wt,a;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n,&p,&q);
        for(i = 0,wt = 0,ans = 0;i < n;i++){
        	scanf("%d", &a);
        	if(i < p && wt < q){
        		wt += a;
        		if(wt <= q) ans++;
        	}
        }
        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}