#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int T,cn = 1,i;

    unsigned long long fact[22],n;
    fact[0] = 1;
    for(i = 1;i < 22;i++){
        fact[i] = i*fact[i-1];
    }


    scanf("%d", &T);
    while( T-- ){
        scanf("%llu", &n);
        stack <int> a;

        for(i = 20;i >= 0;i--){
            if(fact[i] <= n && n > 0){
                n -= fact[i];
                a.push(i);
            }
        }
        printf("Case %d: ",cn++);
        if( n == 0 ){
            while(a.size() > 1){
                printf("%d!+",a.top());
                a.pop();
            }
            printf("%d!\n",a.top());
            a.pop();
        }
        else{
            printf("impossible\n");
        }
    }

    return 0;
}

