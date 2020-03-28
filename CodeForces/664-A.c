#include<stdio.h>
#include<string.h>

int main()
{
    char n1[102], n2[102];

    scanf("%s%s", n1, n2);
    if(!strcmp(n1, n2))
        printf("%s", n1);
    else
        printf("1");

    return 0;
}