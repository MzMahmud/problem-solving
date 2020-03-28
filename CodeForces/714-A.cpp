#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    long long l1,l2,r1,r2,k,ans;

    cin >> l1 >> r1 >> l2 >> r2 >> k;
    //cout << l1 << r1 << l2 << r2 << k;
    if(l2 >= l1 && l2 <= r1 ){
        ans = min(r1,r2) - (l2 - 1);
        if(k >= l2 && k <= r1)
            ans--;
    }
    else if(l1 >= l2 && l1 <= r2 ){
        ans =  min(r1,r2) - (l1 - 1);
        if(k >= l1 && k <= r2)
            ans--;
    }
    else ans = 0; 
         
    printf("%I64d\n",ans);

    return 0;
}