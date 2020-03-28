#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
    //freopen("Input.txt","r",stdin);
    int n,taxi,s[100003],l,r,flag;
    scanf("%d", &n);

    for(l = 0;l < n;l++){
        scanf("%d", &s[l]);
    }
    sort(s,s+n);

    taxi = n;
    for(l = 0,r = n-1;l < r; ){
        flag = 0;
        while( (s[l] + s[r]) <= 4 && l < r){
            flag = 1;
            s[l] = s[l] + s[r];
            taxi--;
            r--;
        }
        if( flag ) l++;
        else       r--;
    }
    printf("%d\n",taxi);
    return 0;
}