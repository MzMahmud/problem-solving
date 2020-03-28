#include <iostream>

using namespace std;

int main()
{
    int n,i,j = 0,k,ans = 90,f = 1;

    cin>>n;
    while( n-- ){
        cin>>i;
        k = i - j;
        j = i;
        if( k > 15 && f){
            ans = j - k + 15;
            f   = 0;
        }
    }
    if( !f ){
        if( 90 - i > 15 )
            ans = i + 15;
    }
    cout<<ans<<endl;
    return 0;
}