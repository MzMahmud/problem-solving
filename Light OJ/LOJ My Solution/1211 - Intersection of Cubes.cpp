/*
ALGO:
    If the problem is thought dimension down to 1D
    its easier. :)
    By the way here volume of intersection means the
    volume that is common to all cubes. :V
    For 1D:
    --------------
      --------
    ------
       ---------------
    So the common part is the difference of the highest
    leftmost point and lowest right most point.
    if highest leftmost point < lowest right (this case)
    ----------------
       --------
            -----
                  ---------
    then there is no common segment.
    this holds for 2D and 3D as the region is axis parallel :)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int n,a,ans;
        int left[3] = {0,0,0},right[3] = {1000,1000,1000};
        /*initially the left most and right most in set the
         *lowest and highest value possible in the problem */
        scanf("%d",&n);
        while(n--){
            for(int i = 0;i < 3;i++){
                scanf("%d",&a);
                if(a > left[i]) left[i] = a;
            }
            for(int i = 0;i < 3;i++){
                scanf("%d",&a);
                if(a < right[i]) right[i] = a;
            }
        }
        if( (left[0] < right[0])&&(left[1] < right[1])&&(left[2] < right[2]) )
             ans = (right[0]-left[0])*(right[1]-left[1])*(right[2]-left[2]);
        else ans = 0;
        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}
