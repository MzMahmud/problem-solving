/*
    //LOJ 1275 - Internet Service Providers
    Author: Moaz Mahmud
    Date  : 14 May,2017
    My Solution:
        y = cx - nx^2
        y_max is there where d/dx(y) = 0 -> x = c/(2n)
        but its needed to be integer.

        case 1: if n = 0
                    return 0
        case 2: if x is integer
                    return x
        case 3: if y(ceil(x)) > y(floor(x))
                    return ceil(x)
        case 4: else
                    return floor(x)

        now this can be said because y is a reverse parabola.
        from top the farther left or right is gone the value reduces gradually.
    END
*/

#include <cstdio>
#include <cmath>
#define pro(x) (x*(c - x*n))

using namespace std;

int solve(int n,int c){
    if(!n) return 0;
    double ans = c/(2.0*n);
    int fa = floor(ans),ca = ceil(ans);
    if(fa == ca) return fa;
    if(pro(ca) > pro(fa)) return ca;
    return fa;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n,c;
        scanf("%d%d",&n,&c);
        printf("Case %d: %d\n",cn++,solve(n,c));
    }
    return 0;
}

