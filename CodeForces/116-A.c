#include <stdio.h>
#include <stdio.h>

int main()
{
    int n,a,b,sum = 0,max = -1;

    scanf("%d", &n);

    while(n--){
        scanf("%d%d",&a,&b);
        sum += (b-a);
        if(sum > max)
            max = sum;
    }
    if(max < 0)
        printf("0\n");
    else
        printf("%d\n",max);


    return 0;
}