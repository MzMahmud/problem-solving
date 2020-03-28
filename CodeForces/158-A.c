#include <stdio.h>

int main()
{
    int score[53],n,k,count,i;

    scanf("%d%d", &n,&k);

    for(i = 0;i < n;i++)
        scanf("%d", &score[i]);

    count = 0;
    for(i = 0;i < n;i++){
    if(score[i] < score[k-1] || score[i] <= 0)
            break;
         count++;
    }
    printf("%d\n",count);

    return 0;
}