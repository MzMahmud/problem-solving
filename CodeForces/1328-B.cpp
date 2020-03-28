#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int T;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        
        char str[n + 1];
        memset(str,'a',n + 1);
        str[n] = '\0';
        
        int i = floor( (sqrt(8.0 * (k-1) + 1.0) + 1.0)/2.0 );
        int b1 = n - 1 - i;
        int l  = (i & 1) ? (i - 1)/2*i : i/2*(i-1); 
        int b2 = n - 1 - (k - l - 1);
        
        str[b1] = str[b2] = 'b';
        
        printf("%s\n",str);
    }
    return 0;
}