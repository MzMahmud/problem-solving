#include <stdio.h>

int main()
{
    freopen("Input.txt","rt",stdin);
    int tc,cn = 1,i,j,n,m,num[103],num1[103],y,z;
    char c;

    scanf("%d",&tc);
    while( tc-- ){

        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);

        while( m-- ){
            scanf(" %c",&c);
            if(c == 'P'){
                scanf("%d%d",&y,&z);
                j = num[y];
                num[y] = num[z];
                num[z] = j;
            }
            else if(c == 'S'){
                scanf("%d",&j);
                for(i=0;i<n;i++)
                    num[i] += j;
            }
            else if(c == 'M'){
                scanf("%d",&j);
                for(i=0;i<n;i++)
                    num[i] *= j;
            }
            else if(c == 'D'){
                scanf("%d",&j);
                for(i=0;i<n;i++)
                    num[i] /= j;
            }
            else if(c == 'R'){
                for(i=0,j=n-1;i<n,j>=0;i++,j--)
                    num1[i] = num[j];
                for(i=0;i<n;i++)
                    num[i] = num1[i];
            }
        }

        printf("Case %d:\n",cn++);
        for(i=0;i<n;i++)
            printf("%d%c",num[i],i == n-1?'\n':' ');

    }
    return 0;
}
