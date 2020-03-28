#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

typedef long long ll;
using namespace std;


int main()
{
    long double k,a,b,ans;
    cin>>k>>a>>b;
    ans = floor(b/(k*1.0)) - floor((a-1)/(k*1.0));
    cout<<(long long)ans<<endl;
    return 0;
}