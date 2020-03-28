#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

typedef long long ll;
using namespace std;

int main()
{
    int a,b,c;

    cin>>a>>b>>c;

    if( c == 0 ){
        if( a == b )
             cout<<"YES\n"<<endl;
        else cout<<"NO\n"<<endl;
    }
    else{

        if( (b-a) % c == 0 && (b-a)/c >= 0 )
             cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}