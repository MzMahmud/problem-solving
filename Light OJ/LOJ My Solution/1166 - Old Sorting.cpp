
/*
    LOJ 1166 - Old Sorting
    Author: Moaz Mahmud
    Date  : 28 Oct,2017

    My Solution:
        for every place if its misplaced find proper one and
        swap and carry on.
    END :D :D
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        vector<int> a;
        for(int i = 0;i < n;i++){
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        int swaps = 0;
        for(int i = 0;i < n;i++){
            if(a[i] != (i+1)){
                for(int j = i+1;j < n;j++){
                    if( a[j] == (i+1) ){
                        swap(a[i],a[j]);
                        swaps++;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %d\n",cn++,swaps);
    }
    return 0;
}

