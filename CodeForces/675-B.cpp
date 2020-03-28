#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define Abs(x) (x < 0 ? -x : x)

typedef long long ll;
using namespace std;

int main()
{
    ll a,b,c,d,n,ans;

    cin>>n>>a>>b>>c>>d;

    ans  =  n*(n - max( Abs( (c+d-a-b) ) , Abs( (a+c-b-d) )));
    if( Abs( (b-c) ) >= n || Abs( (a-d) ) >= n || ans < 0){
        ans = 0;
    }
    cout<<ans<<endl;
    return 0;
}