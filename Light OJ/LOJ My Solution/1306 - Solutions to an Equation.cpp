/*
    LOJ 1306 - Solutions to an Equation
    Author: Moaz Mahmud
    Date  : 01 Nov,2017

    My Solution:
        This is a problem of Linear Diophantine Equation.
        That is,ax + by = c with integer solution.
        if gcd(a,b) ~| c : no solution
        Let g = gcd(a,b).
        general solution,
            x = x' + (b/g)t;
            y = y' - (a/g)t;//t is an integer parameter
        (x',y') is a particular solution.Its found by Extended Euclidean Algorithm.
        Then Just count the #solutions in [x1,x1] and [y1,y2]
        by dividing a,b,c by g and making them new a,b,c
            x = x' + b*t;
            y = y' - a*t;
        now:
            x1 <= x' + b*t <= x2
            y1 <= y' - a*t <= y2
        then this can be solved to take the accepted range of t.
    END :D :D
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX(x,y) (x > y? x : y)
#define MIN(x,y) (x < y? x : y)

using namespace std;

typedef long long ll;

ll egcd (ll a,ll b, ll &x, ll &y){
    if(!a){
        x = 0;y = 1;
        return b;
    }
    ll x1,y1;
    ll d = egcd(b%a,a,x1,y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}

inline bool between(ll x,ll a,ll b){return (a <= x) && (x <= b);}

ll solve(ll input[]){
    ll a,b,c,x1,x2,y1,y2,x,y;
    a  = input[0];b  = input[1];c = -1*input[2];
    x1 = input[3];x2 = input[4];
    y1 = input[5];y2 = input[6];

    if(!(a||b)){
        if(!c) return (x2-x1+1)*(y2-y1+1);
        else   return 0;
    }
    ll g = __gcd(abs(a),abs(b));
    if(c%g) return 0;

    a /= g;b /= g;c /= g;
    g = egcd(a,b,x,y);
    x *= (c/g);y *= (c/g);

    if(!a){
        if(between(y,y1,y2)) return (x2-x1+1);
        else                 return  0;
    }
    if(!b){
        if(between(x,x1,x2)) return (y2-y1+1);
        else                 return  0;
    }

    ll l1,l2,h1,h2,l,h;
    if(b > 0)
        h1 = floor((x2-x)/(abs(b)*1.0)),l1 = ceil((x1-x)/(abs(b)*1.0));
    else
        h1 = floor((x-x1)/(abs(b)*1.0)),l1 = ceil((x-x2)/(abs(b)*1.0));

    if(a > 0)
        h2 = floor((y-y1)/(abs(a)*1.0)),l2 = ceil((y-y2)/(abs(a)*1.0));
    else
        h2 = floor((y2-y)/(abs(a)*1.0)),l2 = ceil((y1-y)/(abs(a)*1.0));

    l = MAX(l1,l2);h = MIN(h1,h2);
    return (h < l)? 0 : (h-l+1);
}

int main(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        ll input[7];
        for(int i = 0;i < 7;i++) scanf("%lld", &input[i]);
        printf("Case %d: %lld\n",cn++,solve(input));
    }
    return 0;
}
