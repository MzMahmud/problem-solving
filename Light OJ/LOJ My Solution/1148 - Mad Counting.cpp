/*
    //LOJ 1148 - Mad Counting
    Author: Moaz Mahmud
    Date  : 06 May,2017

    My Solution:
        the observation is that to minimize the people
        telling the same number have to be in same group.
        2 2 2 1 1 1 1 3 3 3 2 2 2 2
        now all the 2's can't be in a single group
        so there must be multiple group with size 2 + 1 = 3.
        number of groups = ceil((#of 2's)/3)
        so its the process.
    END
*/

#include<cstdio>
#include<cmath>
#include<set>
#define SIZE 1000005

using namespace std;

int main() {
    //freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        set<int> number;
        int a[SIZE] = {0};
        int n,u;
        scanf("%d",&n);
        long long ans = 0;
        while(n--){
            scanf("%d", &u);
            a[u]++;
            number.insert(u);
        }
        set<int>::iterator it = number.begin();
        while(it != number.end()){
            int s = *it;
            int k = (s+1)*ceil(a[s]/(s+1.0));
            ans += k;
            it++;
        }
        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}
