#include <stdio.h>
#define size 30005

long long MaxArea(long long his[],long long n);

int main()
{
    //freopen("Input Maximum Ractengular Area in Histogram.txt","r",stdin);

    int T,cn = 1,i;
    long long ans,n,his[size];

    scanf("%d", &T);
    while(T--){
        scanf("%lld", &n);
        for(i = 0;i < n;i++){
            scanf("%lld", &his[i]);
        }
        ans = MaxArea(his,n);
        printf("Case %d: %lld\n", cn++,ans);
    }

    return 0;
}

long long MaxArea(long long his[],long long n)
{
    int increasigIndex[size],top = -1,maxArea = -1,i,area;

    i = 0;
    while(i < n){
        if( top == -1 || his[i] >= his[increasigIndex[top]] ){
            top++;
            increasigIndex[top] = i;
            i++;
        }
        else{
            if(top == 0)
                  area = his[increasigIndex[top]]*i;

            else  area = his[increasigIndex[top]]*(i - increasigIndex[top-1] - 1);

            top--;
            if(area > maxArea)
                maxArea = area;
        }
    }

    while( top >= 0){
          if(top == 0)
                area = his[increasigIndex[top]]*i;
          else  area = his[increasigIndex[top]]*(i - increasigIndex[top-1] - 1);

          if(area > maxArea)
             maxArea = area;

          top--;
    }

    return maxArea;
}
