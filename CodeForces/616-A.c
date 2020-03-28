#include <stdio.h>
#include <string.h>

int digits(char a[])
{
    int lz = 0,i;

    for(i = 0; i < strlen(a);i++){
        if(a[i] == '0')
           lz++;
        else
           return (strlen(a) - lz);
    }
    return 1;
}

int index(char a[])
{
    int i;

    for(i = 0; i < strlen(a);i++){
        if(a[i] != '0')
           return i;
    }
    return 0;
}

int compare(char a[],char b[])
{
    if( digits(a) > digits(b) )
        return 1;

    if( digits(a) < digits(b) )
        return -1;

    int i,j,k;

    for(k = 0,i = index(a),j = index(b);k < digits(a);k++){
        if(a[i+k] > b[j+k])  return 1;
        if(a[i+k] < b[j+k])  return -1;
    }
    return 0;
}

int main()
{
    char n1[1000002],n2[1000002],t;

    scanf("%s\n%s",n1,n2);

    //printf("len1 %d len2 %d\n",strlen(n1),strlen(n2));
    t = compare(n1,n2);

    //printf("dig1 %d\tdig2 %d\n",digits(n1),digits(n2));

         if( t ==  1 )  printf(">\n");
    else if( t == -1 )  printf("<\n");
    else                printf("=\n");


    return 0;
}