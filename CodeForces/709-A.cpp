#include <iostream>

using namespace std;

int main(){
    long long int count = 0,n,d,b,Or,gur = 0;
    cin >> n >> b >> d;
    while(n--){
    	if(gur > d){
            count++;
            gur = 0;
        }
        cin >> Or;
        if(Or <= b)
            gur += Or;
    }
    if(gur > d){
        count++;
        gur = 0;
    }
    cout << count << endl;
    return 0;
}