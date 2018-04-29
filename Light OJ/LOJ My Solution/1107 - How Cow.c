#include <stdio.h>

int main()
{
    //freopen("Input.txt","rt",stdin);
    //freopen("Output.txt","wt",stdout);

    int Case,caseno = 1;
    int x1,y1,x2,y2,cow,x,y;

    scanf("%d" ,&Case);

    while( Case-- ){
        scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
        scanf("%d", &cow);

        printf("Case %d:\n", caseno++);
        while( cow-- ){
            scanf("%d%d", &x,&y);

            if( x > x1 && x < x2 && y > y1 && y < y2 )
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
