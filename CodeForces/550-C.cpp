#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    
    cin >> s;

    if(s.length() == 1){
        if(!((s[0]-'0')%8)){ cout << "YES" << endl << s << endl;return 0;}
    }

    if(s.length() == 2){
        int a = s[0]-'0',b = s[1]-'0';
        if(!(a%8)){ cout << "YES" << endl << a << endl;return 0;}
        if(!(b%8)){ cout << "YES" << endl << b << endl;return 0;}
        if(!((10*a+b)%8)){ cout << "YES" << endl << (10*a+b) << endl;return 0;}
    }

    for(int i = s.length() - 1;i >= 0;i--){
        for(int j = i+1;j < s.length();j++){
            for(int k = i-1;k >= 0;k--){
                int a,b,c;
                b = s[i] - '0';
                a = s[k] - '0';
                c = s[j] - '0';
                
                if(!(c%8)){ cout << "YES" << endl << c << endl;return 0;}
                if(!(b%8)){ cout << "YES" << endl << b << endl;return 0;}
                if(!(a%8)){ cout << "YES" << endl << a << endl;return 0;}
                if(!((10*b + c)%8)){ cout << "YES" << endl << (10*b + c) << endl;return 0;}
                if(!((10*a + c)%8)){ cout << "YES" << endl << (10*a + c) << endl;return 0;}
                if(!((10*a + b)%8)){ cout << "YES" << endl << (10*a + b) << endl;return 0;}
                if(!((100*a+10*b + c)%8)){ cout << "YES" << endl << (100*a+10*b + c) << endl;return 0;}
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}