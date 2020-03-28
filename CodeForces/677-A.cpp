#include <iostream>

using namespace std;

int main()
{
    int n,h,a,cn=0 ;
    cin>>n>>h;
    while(n--){
        cin>>a;
        if(a <= h) cn++;
        else       cn+=2;
    }
    cout<<cn<<endl;
    return 0;
}