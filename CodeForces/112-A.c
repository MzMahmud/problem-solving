#include <stdio.h>
#include <stdio.h>



int ans(char a[],char b[])
{
    int i;

    for(i = 0;i < strlen(a);i++){
        if(a[i] >= 'A' && a[i] <= 'Z')
            a[i] = a[i] - 'A' + 'a';
        if(b[i] >= 'A' && b[i] <= 'Z')
            b[i] = b[i] - 'A' + 'a';

        if( a[i] > b[i] )
            return 1;
        else if( a[i] < b[i] )
            return -1;
    }
    return 0;
}

int main()
{
    int i,count = 1;
    char a[102],b[102];

    scanf("%s\n%s", a,b);

    printf("%d\n", ans(a,b));

    return 0;
}