#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int T,cn = 1;
    cin >> T;
    while(T--){
        string a;
        long long b;
        cin >> a >> b;
        if(b < 0) b*= -1;
        printf("Case %d: ",cn++);

        long long mod,n = 0;
        for(int i = 0;i < a.length();i++){
            if(a[i] != '-')
                n = 10*n + (a[i]-'0');
            if(n > b) n %= b;
            mod = n%b;
        }
        if( !(mod%b) ) cout << "divisible" << endl;
        else           cout << "not divisible" << endl;
    }
    return 0;
}
