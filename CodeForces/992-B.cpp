#include <bits/stdc++.h>

using namespace std;

#define inRange(x,a,b) (a<=x&&x<=b)

typedef unsigned long long ull;

int main(){
	ull l,r,x,y;
	int ans = 0;
	
	cin >> l >> r >> x >> y;
	 
	if(y%x){
		cout << ans << endl;
		return 0;
	}
	
	y /= x;
	
	for(ull a = 1;a*a <= y;a++){
		if(!(y%a)){
			ull b = y/a;
			if( inRange((a*x),l,r) && inRange((b*x),l,r) && __gcd(a,b) == 1){
				if(a == b) ans+= 1;
				else	   ans+= 2;
			}
		}		
	}
	cout << ans << endl;
	return 0;
}