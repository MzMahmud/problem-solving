#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

typedef long long ll;
using namespace std;

int main()
{
    string a[1008];
    a[0] = '0';
    int i,j = 1,x,y,z,n;
    for(i = 1;j < 1005;i++){
        x = (i/100) % 10;
        if( x ) a[j++] = '0' + x;

        y = (i/10) % 10;
        if( x != 0 )      a[j++] = '0' + y;
        else if( y != 0 ) a[j++] = '0' + y;

        z = (i) % 10;
        if( x != 0 )      a[j++] = '0' + z;
        else if( y != 0 ) a[j++] = '0' + z;
        else if( z != 0 ) a[j++] = '0' + z;
    }
    //for(i = 0;i < 1005;i++) cout<<a[i];

    cin>>n;
    cout<<a[n]<<endl;
    return 0;
}