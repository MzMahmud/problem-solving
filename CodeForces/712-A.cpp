#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    int n,a,b;
    cin >> n;
    cin >> a;
    for(int i = 2;i <= n;i++){
        cin >> b;
        cout<< a+b << ' ';
        a = b;
    }
    cout<< a << endl;

    return 0;
}