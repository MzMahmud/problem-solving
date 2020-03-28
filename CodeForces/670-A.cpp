#include <iostream>

using namespace std;

int main()
{
    int n,mod,mx,mn;

    cin>>n;
    mod = n % 7;
    mn = (n/7)*2;
    if( mod == 1 )
        mx = mn + 1;
    else if( mod == 6 )
        mx = mn + 2,mn++;
    else if( !mod )
        mx = mn;
    else
        mx = mn + 2;

    cout<<mn<<' '<<mx<<endl;
    return 0;
}