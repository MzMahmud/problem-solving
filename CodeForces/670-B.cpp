#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ll n,k,index,c = 1,a;

    cin>>n>>k;
    a = ceil( ( sqrt( (8.0*k - 3.0) ) - 3.0 )/2.0 );
    index = k - (a*(a+1)/2);

    while( n-- ){
        if( c == index )
             cin>>a;
        else cin>>k;
        c++;
    }
    cout<<a<<endl;
    return 0;
}