#include <stdio.h>
#include <string.h>

int vowel(char a)
{
    switch(a){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return 1;
    }
    return 0;
}

char lower(char a)
{
    if( a >= 'A' && a <= 'Z')
        return (a - 'A') + 'a';

    return a;
}

int main()
{
    int i;
    char s1[103];

    scanf("%s", s1);

    for(i = 0;i < strlen(s1);i++){
        s1[i] = lower(s1[i]);
        if( vowel( s1[i] ) == 0){
           printf(".%c",s1[i]);
        }
    }
    printf("\n");

    return 0;
}