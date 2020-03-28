#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <string>


using namespace std;



int main()
{
    int a[13][2],i,j,n,k,cn = 0;
    char com[20];

    cin>>n;
    for(i = 0;i < n;i++){
        cin>>com>>a[i][1];

        if( com[0] == 'A' ) a[i][0] = 1;
        if( com[0] == 'S' ) a[i][0] = 2;
        if( com[0] == 'M' ) a[i][0] = 3;
        if( com[0] == 'D' ) a[i][0] = 4;
    }

    for(j = 1;j <= 100;j++){
        k = j;
        for(i = 0;i < n;i++){
            if( a[i][0] == 1 ) k += a[i][1];
            else if( a[i][0] == 2 && k >= a[i][1] ) k -= a[i][1];
            else if( a[i][0] == 3 ) k *= a[i][1];
            else if( a[i][0] == 4 && !(k%a[i][1]) ) k /= a[i][1];
            else break;
        }
        if(i < n) cn++;
    }
    cout<<cn<<endl;
    return 0;
}