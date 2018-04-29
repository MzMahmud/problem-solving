#include <stdio.h>

int main()
{
    int T,cn = 1,a,b;	
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&a,&b);
		printf("Case %d: %d\n",cn++,a+b);
	}
    return 0;
}

