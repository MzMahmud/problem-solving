#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

typedef long long ll;
using namespace std;

int main()
{
    int n,i,m,a,minIndex,maxIndex;

    cin>>n;
    for(i = 1;i <= n;i++){
        cin>>a;
        if(a == 1) minIndex = i;
        if(a == n) maxIndex = i;
    }
    m = abs( (maxIndex-minIndex) );

    i = abs( (1-minIndex) );
    if(i > m) m = i;
    i = abs( (n-minIndex) );
    if(i > m) m = i;
    i = abs( (maxIndex-1) );
    if(i > m) m = i;
    i = abs( (maxIndex-n) );
    if(i > m) m = i;

    cout<<m<<endl;
    return 0;
}