#include <iostream>
#include <cstdio>
#include <algorithm>

#define Abs(x) ( x < 0 ? -x : x )
using namespace std;


int main()
{
    int n;
    int a[200002],b[200002];


    cin>>n;
    int i;
    for(i = 0;i < n;i++){
        cin>>a[i];
        b[a[i]-1] = i;
    }

    long long ans = 0;
    for(i = 0;i < n-1;i++){
        ans += Abs( (b[i] - b[i+1]) );
    }
    cout<<ans<<endl;
    return 0;
}