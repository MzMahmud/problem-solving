#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("Input.txt", "rt",stdin);
    int tc,cn = 1,n,w,i,j,top,count,x,y[50003];

    scanf("%d",&tc);
    while( tc-- ){
            scanf("%d%d",&n,&w);
            for(i=0;i<n;i++)
                scanf("%d%d",&x,&y[i]);

            sort(y,y+n);
            count=1,top=y[0]+w;
            for(i=1;i<n;i++){
                if(y[i]<=top)
                     continue;
                else{
                    count++;
                    top = y[i]+w;
                }
            }
            printf("Case %d: %d\n",cn++,count);
    }
    return 0;
}
