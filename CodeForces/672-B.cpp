#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int letter[26];

int main()
{
    char a[100003];
    int l,c = 0,i;

    cin>>l;
    for(i = 0;i < l;i++){
        cin>>a[i];
        letter[ a[i]-'a' ]++;
    }
    if(l > 26){
       cout<<-1<<endl;
       return 0;

    }
    for(i = 0;i < 26;i++){
        if( letter[i] > 0)
            c++;
    }
    cout<<l-c<<endl;
    return 0;
}