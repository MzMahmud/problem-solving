#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int T,cn = 1;
    cin >> T;
    while(T--){
        double n,ans = 1.0;
        int i,lo;
        cin >> n;
        for(i = 0; ans > 0.5; i++)
            ans = ans *(n-i)*1.0 /(n*1.0);

        printf("Case %d: %d\n",cn++,i-1);
    }
    return 0;
}
