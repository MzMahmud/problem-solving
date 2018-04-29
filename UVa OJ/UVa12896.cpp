#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    string key[10] = {
        " ",
        ".,?\"", 
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    int T,l,p,stroke[110];
    cin >> T;
    while(T--){
        cin >> l;
        for(int i = 0;i < l;i++)
            cin >> stroke[i];

        for(int i = 0;i < l;i++){
            cin >> p;
            cout << key[stroke[i]][p-1];
        }
        cout << endl;
    }

    return 0;
}
