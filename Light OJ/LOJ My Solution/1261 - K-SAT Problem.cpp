#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    int T,cn = 1;
    cin >> T;
    while(T--){
        int n,m,k,w,p,wish[32][32];
        bool soln[32] = {},yes = true,t = false;

        cin >> n >> m >> k;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < k;j++)
                cin >> wish[i][j];

        cin >> p;
        while(p--){
            cin >> w;
            soln[w-1] = true;
        }

        for(int i = 0;i < n;i++){
            t = false;
            for(int j = 0;j < k;j++)
                t = t || ( (wish[i][j] > 0?true:false) == soln[abs(wish[i][j])-1] );

            yes = yes && t;
        }
        if(yes) printf("Case %d: Yes\n",cn++);
        else    printf("Case %d: No\n",cn++);
    }
    return 0;
}
