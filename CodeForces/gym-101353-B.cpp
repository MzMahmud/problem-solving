#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	long double n,r,p;
	long long res;
	int T,cn = 1;
	scanf("%d",&T);
	while(T--){
		//scanf("%llf%llf%llf",&n,&r,&p);
		cin >> n >> r >> p;
		res = ceil( ( (log(p) - log(n))/(log(1+r/100.0)) ) );
		if(res < 0) res = 0;
		//printf("Case %d: %I64d\n",cn++,res);
		cout << "Case " << cn++ << ": " << res << endl;
	}
	return 0;
}