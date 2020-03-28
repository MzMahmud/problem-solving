#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n,l,m = -1,sum = 0,a,b;

    scanf("%d", &n);

    while( n-- ){
        scanf("%d", &l);
        sum += l;
        if(l > m)
            m = l;
    }
    sum -= m;

    a = max(m,sum);
    b = min(m,sum);

    printf("%d\n",a-b+1);

    return 0;
}