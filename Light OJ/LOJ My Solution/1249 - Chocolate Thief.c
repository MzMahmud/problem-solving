#include <stdio.h>

struct student{
    char name[22];
    double  volume;
};

int main()
{
    freopen("Input.txt", "rt",stdin);
    freopen("Output.txt", "wt",stdout);

    int t,c = 1,n,l,b,h,max,min,i,m,M;

    struct student std[100];

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        printf("Case %d: ",c++);

        for(i = 0;i < n;i++){
            scanf("%s%d%d%d", &std[i].name,&l,&b,&h);
            std[i].volume = l*b*h;
        }

        m = 0,M = 0,max = std[0].volume,min = std[0].volume;
        for(i = 0;i < n;i++){
            if(std[i].volume > max){
                max = std[i].volume;
                M = i;
            }

            if(std[i].volume < min){
                min = std[i].volume;
                m = i;
            }
        }

        if( max == min )
            printf("no thief\n");
        else
            printf("%s took chocolate from %s\n",std[M].name,std[m].name);
    }
    return 0;
}
