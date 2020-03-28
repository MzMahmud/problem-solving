#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,d,x = 0,face = 1,y = 0,facey = 1;
    string dir;

    //freopen("in.txt","r",stdin);
    cin >> n;
    while(n--){
        cin >> d >> dir;
        if((x == 0 && dir != "South")||(x == 20000 && dir != "North")){
            cout << "NO" << endl;
            return 0;
        }
        if(dir == "North") x -= d;
        if(dir == "South") x += d;
        if(x > 20000 || x < 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(x == 0) cout << "YES" << endl;
    else       cout << "NO" << endl;
    return 0;
}