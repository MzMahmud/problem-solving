#include <bits/stdc++.h>

using namespace std;

int tau(int n){
    int c = 1;
    while( !(n%2) ){
        c++;
        n /= 2;
    }
    int d = 0;
    for(int i = 1;i*i <= n;i += 2){
        if(!(n%i)){
            d++;
            if( i != (n/i) ) d++;
        }
    }
    return d*c;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int a,b,m = -1,md = -1;
        scanf("%d%d", &a,&b);
        for(int i = a;i <= b;i++){
            int t = tau(i);
            if(t > md){
                m = i;
                md = t;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,m,md);
    }
    return 0;
}
