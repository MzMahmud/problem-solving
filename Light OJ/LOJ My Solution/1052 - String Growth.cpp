/*
    1052 - String Growth
    Author: Moaz Mahmud
    Date  : 07 Nov,2017

    My Solution:
        Let a(n),b(n),f(n) be the #a's,#b's and length of n-th string.
        b(n+1) = a(n)+b(n) = f(n);
        a(n+1) = b(n) = f(n-1);
        Now,f(n+1) = a(n)+b(n) = f(n)+f(n-1);
        So,f(n) = f(n-1)+f(n-2);
        Convert this recurrence to matrix.
        {f(n),f(n-1)} = {{1,1},{1,0}}^(n-2)*{f(2),f(1)};

        Given,f(n) = x,f(m) = y.
        Then two equation comes for f(2) and f(1).
        Solve them to get f(2),f(1) and find f(k).

        Case For IMPOSSIBLE:
            - if f(2),f(1) is not positive integer
            - if f(2) < f(1)
            - if f(2) > 2f(1)

    END :D :D
*/
#include <cstdio>
#define DIM 2
#define MOD 1000000007

typedef long long ll;

using namespace std;


//NOTATIONO [A] = matrix a; DIM = dimension
///operation :: result = [a]*[b]
///VERTY IMPORTANT :: never try to do multiply(a,b,a) or multiply(a,b,b)
///use different matrix for result
void multiply(ll a[DIM][DIM],ll b[DIM][DIM],ll result[DIM][DIM]){
    for(int i = 0;i < DIM;i++){
        for(int j = 0;j < DIM;j++){
            result[i][j] = 0;
            for(int k = 0;k < DIM;k++){
                result[i][j] += (a[i][k] * b[k][j]);
                if(result[i][j] >= MOD) result[i][j] %= MOD;
            }
        }
    }
}
///operation :: [to]  = [from]
void copy(ll to[DIM][DIM],ll from[DIM][DIM]){
    for(int i = 0;i < DIM;i++)
        for(int j = 0;j < DIM;j++){
            to[i][j] = from[i][j];
            if(to[i][j] >= MOD) to[i][j] %= MOD;
        }
}

///operation :: [result] = pow([a],b)
///VERTY IMPORTANT :: never try to do power(a,b,a)
///use different matrix for result
void power(ll a[DIM][DIM],ll b,ll result[DIM][DIM]){
    if(!b){
       ll I[DIM][DIM] = {};
       for(int i = 0;i < DIM;i++) I[i][i] = (ll)1;//making identity matrix
       copy(result,I);return;//like return 1
    }
    ll x[DIM][DIM],y[DIM][DIM];
    power(a,b/2,x);//x = power(a,b/2)
    multiply(x,x,y);//y = x*x
    if(b&1){
        multiply(y,a,x);//x = y*a
        copy(y,x);//y = x;
    }
    copy(result,y);//result = y;like return result
}
ll solve(ll a[],ll b[],ll x,ll y,ll k){
    if((a[0]*b[1]) == (a[1]*b[0])) return -1;//Discriminant = 0

    //done solution with creamer rule
    ll d  = (a[0]*b[1]) - (a[1]*b[0]);
    ll dx = (  x *b[1]) - (a[1]*  y );
    ll dy = (a[0]*  y ) - (  x *b[0]);

    if((dx%d)||(dy%d)) return -2;//NOT an integer

    ll init[2];
    init[0] = dx/d;//init[0] = f(2)
    init[1] = dy/d;//init[1] = f(1)

    if(init[0] <= 0 || init[1] <= 0) return -3;//zero or negative integer
    if(init[0] < init[1]) return -4;//f(2) < f(1) which is not possible
    if(init[0] > 2*init[1] ) return -5;//f(2) > 2f(1) which is not possible

    if(k == 1) return init[1] % MOD;
    if(k == 2) return init[0] % MOD;

    ll mat[2][2] = {{1,1},
                    {1,0}},res[2][2];

    power(mat,k-2,res);

    return ( (init[0]*res[0][0])%MOD + (init[1]*res[0][1])%MOD ) % MOD;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        ll n,x,m,y,k,a[2],b[2];
        ll mat[2][2] = {{1,1},
                        {1,0}},res[2][2];

        scanf("%lld%lld",&n,&x);
        scanf("%lld%lld",&m,&y);
        scanf("%lld",&k);

             if(n == 1) a[0] = 0,a[1] = 1;
        else if(n == 2) a[0] = 1,a[1] = 0;
        else{
            power(mat,n-2,res);
            a[0] = res[0][0],a[1] = res[0][1];
        }

             if(m == 1) b[0] = 0,b[1] = 1;
        else if(m == 2) b[0] = 1,b[1] = 0;
        else{
            power(mat,m-2,res);
            b[0] = res[0][0],b[1] = res[0][1];
        }
        ll ans = solve(a,b,x,y,k);
        printf("Case %d: ",cn++);
        if(ans  < 0) printf("Impossible\n");
        else         printf("%lld\n",ans);
    }
    return 0;
}
