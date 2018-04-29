/*
    1027 - A Dangerous Maze
    Author: Moaz Mahmud
    Date  : 08 May,2017
*/
#include <cstdio>
#include <algorithm>
#define ABS(x) (x < 0? -1*x : x)

using namespace std;

int main() {
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdo);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n,a,b = 0,sum = 0;
        scanf("%d", &n);
        for(int i = 0;i < n;i++){
            scanf("%d",&a);
            if(a < 0) b++;
            sum += (ABS(a));
        }
        if(b == n)
            printf("Case %d: inf\n",cn++);
        else{
            int g = __gcd(sum,n-b);
            printf("Case %d: %d/%d\n",cn++,sum/g,(n-b)/g);
        }
    }
    return 0;
}

