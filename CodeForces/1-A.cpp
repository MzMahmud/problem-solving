#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int n,m,a,ans;

    cin>>n>>m>>a;
    ans = ceil( n/(a*1.0) )*ceil( m/(a*1.0) );
    cout<<ans<<endl;

    return 0;
}