#include <iostream>

using namespace std;

int main(){
    int x,y,ans;
    char c[3];
    cin>>c;
    x = c[0] - 'a' + 1;
    y = c[1] - '0';
	//cout << 'x' << x << 'y' << y << endl;
    if( (x % 7) == 1 ){
        if((y % 7) == 1){
            cout << 3 << endl;
            return 0;
        }
        cout << 5 << endl;
        return 0;
    }
    if( (y % 7) == 1 ){
        if((x % 7) == 1){
            cout << 3 << endl;
            return 0;
        }
        cout << 5 << endl;
        return 0;
    }
    cout << 8 << endl;
    return 0;
}