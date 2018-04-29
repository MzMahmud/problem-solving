#include <stdio.h>
#include <math.h>

int power2(int );
int d1,d2,d3,d4;

int main()
{
    freopen("Input.txt","rt",stdin);

    int tc,cn = 1,i,j,k,p,m,n;
    char bin[35];
    int bin1[32];

    scanf("%d", &tc);
    while( tc-- ){
        scanf("%d.%d.%d.%d", &d1,&d2,&d3,&d4);
        scanf("%s", bin);

        j = 0;
        for(i = 0;i < 35;i++){
            if(i == 8 || i == 17 || i == 26)
                continue;

            bin1[j++] = bin[i] - '0';
        }

        i = 0,j = 0,k = 0,p = 0;
        for(n = 0,m = 7;n < 8;n++,m--)
            i = i + (bin1[n]*power2(m));

        for(n = 8,m = 7;n < 16;n++,m--)
            j = j + (bin1[n]*power2(m));

        for(n = 16,m = 7;n < 24;n++,m--)
            k = k + (bin1[n]*power2(m));

        for(n = 24,m = 7;n < 32;n++,m--)
            p = p + (bin1[n]*power2(m));

        if( i != d1 || j != d2 || k != d3 || p != d4)
            printf("Case %d: No\n",cn++);
        else
            printf("Case %d: Yes\n",cn++);
    }
    return 0;
}

int power2(int m)
{
    int i = 1;
    while( m-- )
        i = 2*i;
    return i;
}
