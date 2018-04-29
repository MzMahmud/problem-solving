#include <stdio.h>

int main()
{
    //freopen("Input.txt", "rt",stdin);
    //freopen("Output.txt", "wt",stdout);

    int t,c = 1,line,tk,T;
    char word[10];

    scanf("%d", &t);

    while(t--){
        tk = 0;
        scanf("%d", &line);

        printf("Case %d:\n",c++);

        while( line-- ){
                scanf("%s", word);
                if(word[0] == 'r')
                    printf("%d\n",tk);

                else{
                    scanf("%d", &T);
                    tk = tk + T;
                }
        }
    }
    return 0;
}
