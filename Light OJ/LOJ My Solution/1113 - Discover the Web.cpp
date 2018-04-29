#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int T,cn = 1;
    cin >> T;
    while(T--){
        string current,com;
        stack <string> F,B;
        printf("Case %d:\n",cn++);
        current = "http://www.lightoj.com/";
        while(1){
            cin >> com;
            if(com == "VISIT"){
                B.push(current);
                cin >> current;
                cout << current << endl;
                while(!F.empty())
                    F.pop();
            }
            else if(com == "BACK"){
                if(B.empty()) cout << "Ignored" << endl;
                else{
                    F.push(current);
                    current = B.top();
                    B.pop();
                    cout << current << endl;
                }
            }
            else if(com == "FORWARD"){
                if(F.empty()) cout << "Ignored" << endl;
                else{
                    B.push(current);
                    current = F.top();
                    F.pop();
                    cout << current << endl;
                }
            }
            else
                break;
        }
    }
    return 0;
}

