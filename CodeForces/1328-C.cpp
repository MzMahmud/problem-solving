#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int n;
        string x;
        cin >> n >> x;
        
        char a[n + 1],b[n + 1];
        a[n] = b[n] = '\0';
        
        bool equal = true;
        for(int i = 0;i < x.size();i++){
            switch(x[i]){
                case '0':
                    a[i] = b[i] = '0';
                    break;
                case '1':
                    if(equal){
                        a[i] = '0';
                        b[i] = '1';
                    }else{
                        a[i] = '1';
                        b[i] = '0';
                    }
                    equal = false;
                    break;
                case '2':
                    if(equal){
                        a[i] = b[i] = '1';
                    }else{
                        a[i]  = '2';
                        b[i]  = '0';
                        equal = false;
                    }
                    break;
            }
        }
        
        printf("%s\n%s\n",a,b);
    }
    return 0;
}