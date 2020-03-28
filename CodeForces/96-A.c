#include <stdio.h>
#include <stdio.h>

int main()
{
    int i,count = 1;
    char a[102];

    scanf("%s", a);

    for(i = 0;i < strlen(a) - 1;i++){
        if(a[i] == a[i+1])
            count++;
        else
            count = 1;
        if(count == 7)
            break;
    }
    if( count < 7 )
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}