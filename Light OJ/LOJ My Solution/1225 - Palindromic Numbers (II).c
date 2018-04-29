#include <stdio.h>
#include <string.h>

int is_palindom(char word[12]);

int main()
{
    int Case,counter = 1;
    char num[12];

    scanf("%d", &Case);

    while ( Case-- ){
        scanf("%s", num);

        if(is_palindom(num) == 1)
            printf("Case %d: Yes\n", counter++);
        else
            printf("Case %d: No\n", counter++);
    }
    return 0;
}

int is_palindom(char word[12])
{
    int i,j,len;
    len=strlen(word);

        for(i=0,j=len-1;i<len,j>=0;i++,j--){
            if(word[i]!= word[j]) return 0;
        }
    return 1;
}

