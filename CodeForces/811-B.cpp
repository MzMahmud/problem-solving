#include <bits/stdc++.h>
#define SIZE 10005

using namespace std;

pair<int,int> num[SIZE];

int main(){
    //freopen("in.txt", "r",stdin);

    int n,m,a;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%d", &a);
        num[i] = make_pair(a,i+1);
    }

    sort(num,num+n);

    for(int i = 0;i < m;i++){
        int l,r,x,c = 0;
        scanf("%d%d%d",&l,&r,&x);
        for(int i = 0;i < n;i++){
            int ind = num[i].second;
            if(l <= ind && ind <= r){
                if(ind == x) break;
                c++;
            }
        }
        if((l+c) == x) printf("Yes\n");
        else           printf("No\n");
    }
    return 0;
}