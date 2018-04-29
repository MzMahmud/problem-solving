#include <stdio.h>
#include <string.h>

int main()
{
    int Case,counter = 1,my_position,lift_position,time;
    
    scanf("%d", &Case);


    while( Case-- ){
            scanf("%d%d", &my_position,&lift_position);

            time = 4*abs(lift_position - my_position) + 4*my_position + 19;

            printf("Case %d: %d\n",counter++,time);
    }
    return 0;
}
