/*
    //LOJ 1307 - Counting Triangles
    Author: Moaz Mahmud
    Date  : 08 May,2017

    My Solution:
        for a valid triangle triple (a,b,c)[a>=b>=c] b+c>a is true.
        first step is to sort the collection.
        Example:
        3 4 6 7 8 9 16 21
        Now take for example (3,4) -> 7 so a > 7.
        find the sitting position in {6 7 8 9 16 21}
        so only 6 is valid.
        again for (4,8) -> 12 search {9 16 21} only 9 is valid.
    END :D :D

*/
#include<cstdio>
#include<algorithm>
#define SIZE 2009
#define decode(x) (x < 0? -1*(x+1) : x )
using namespace std;

int a[SIZE],n;

int binarySearch(int x,int i,int j){
    int pos,low,up,mid;
    low = i,up  = j;
    while(low <= up){
        mid = (low+up)/2;
        if(a[mid] == x) return mid;
        else if(x > a[mid]) low = mid + 1;
        else if(x < a[mid]) up  = mid - 1;
    }
	if(x > a[mid]) mid++;
    return -1*(mid+1);
}


int main() {
    freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int ans = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);

        sort(a,a+n);
        for(int i = 0;i < (n-2);i++){
            for(int j = i+1;j < (n-1);j++){
                int x = decode( ( binarySearch( a[i]+a[j] , j+1 , n-1 ) ) );
                int y = x - (j+1);
                if(y < 0) y = 0;
                ans += y;
            }
        }
        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}

