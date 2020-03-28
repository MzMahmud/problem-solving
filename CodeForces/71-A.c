#include <stdio.h>
#include <string.h>

int main()
{
    char word[103];
    int T;

    scanf("%d", &T);
    while( T-- ){
        scanf("%s", word);
        if(strlen(word) <= 10)
            puts(word);
        else
            printf("%c%d%c\n",word[0],strlen(word) - 2,word[strlen(word) - 1]);
    }

    return 0;
}