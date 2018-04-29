/*
    //LOJ 1088 - Points in Segments
    Author : Moaz Mahmud
    Date   : 05 May,2017
*/
#include<cstdio>
#define SIZE 100005
#define decode(x) (-1*(x+1))

using namespace std;

int n;

int binarySearch(int x,int a[]){
    int pos,low,up,mid;
    low = 0,up  = n - 1;
    while(low <= up){
        mid = (low+up)/2;
        if(a[mid] == x) return mid;
        else if(x > a[mid]) low = mid + 1;
        else if(x < a[mid]) up  = mid - 1;
    }
    if(x > a[mid]) mid++;
    return -1*(mid+1);
}

int main(){
    freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int q,a,b,low,up;
        int points[SIZE];
        scanf("%d%d", &n,&q);
        for(int i = 0;i < n;i++) scanf("%d",&points[i]);
        printf("Case %d:\n", cn++);
        while(q--){
            scanf("%d%d", &a,&b);
            low = binarySearch(a,points);
            up  = binarySearch(b,points);
            int ans = 1;
            /* (a,b) -> ans = up - low
             * [a,b) -> ans = up - low
             * (a,b] -> ans = up - low + 1
             * [a,b] -> ans = up - low + 1
             * so if b is inclusive then ans = 1 else ans = 0.
             * ans += (up - low) here up,low are proper sitting position
             */
            if(up < 0){up = decode(up);ans = 0;}
            if(low< 0){low= decode(low);}
            ans += (up - low);
            printf("%d\n",ans);
        }
    }
    return 0;
}
