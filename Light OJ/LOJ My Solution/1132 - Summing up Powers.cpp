/*
    LOJ 1132 - Summing up Powers
    Author: Moaz Mahmud
    Date  : 01 July,2018

    My Solution:
        Matrix Exponentiation.
        http://lbv-pc.blogspot.com/2012/05/summing-up-powers.html

    END :D :D
*/

#include <bits/stdc++.h>
#define MAXN 53

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;

template<class T>
class matrix{
public:
    T **a;
    int n;
    matrix(int _n){
        n = _n;
        a = new T*[n];
        for(int i = 0;i < n;i++)
            a[i] = new T[n];

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                a[i][j] = (T) 0;
            }
        }
    }

    matrix(const matrix<T>& mat){
        n = mat.n;
        a = new T*[n];
        for(int i = 0;i < n;i++)
            a[i] = new T[n];

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                a[i][j] = mat.a[i][j];
            }
        }
    }
    ~matrix(){
        for(int i = 0;i < n;i++)
            delete [] a[i];
        delete [] a;
    }
    matrix<T>& operator=(const matrix<T>& mat){
        if (this == &mat)
            return *this;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                a[i][j] = mat.a[i][j];
            }
        }
        return *this;
    }
    matrix<T> operator*(const matrix<T>& mat){
        matrix<T> ret(n);

        for(int i = 0; i < n;i++)
            for(int j = 0; j < n;j++)
                for(int k = 0; k < n;k++)
                    ret.a[i][j] += a[i][k] * mat.a[k][j];


        return ret;
    }
};

template <class T>
matrix<T> power(matrix<T> a,ull b){
    if (!b){
        matrix<T> I(a.n);
        for(int i = 0;i < a.n;i++)
            I.a[i][i] = (T)1;
        return I;
    }
    matrix<T> x(a.n);
    x = power(a,b/2);
    x = x*x;
    if(b&1) x = x*a;
    return x;
}

uint C[MAXN][MAXN];
uint nCr(int n,int r){
    if(r == 0) return C[n][r] = 1;
    if(r > (n/2)) r = n - r;
    if(!C[n][r])
        C[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
    return C[n][r];
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    for(int n = 0;n < MAXN;n++)
        for(int r = 0;r <= n;r++)
            C[n][r] = nCr(n,r);

    int T,cn = 1;
    cin >> T;
    while(T--){
        uint k;
        ull n;
        cin >> n >> k;

        matrix<uint> mat(k+2);
        mat.a[0][0] = 1;
        for(int r = 0;r <= k;r++)
            mat.a[0][r+1] = C[k][r];

        for(int i = 1;i < (k+2);i++){
            for(int j = 0;j <= (k-i+1);j++){
                mat.a[i][i+j] = C[k-i+1][j];
            }
        }
        mat = power(mat,n-1);
        uint ans = 0;
        for(int i = 0;i < (k+2);i++)
            ans += mat.a[0][i];

        cout << "Case " << cn++ << ": " << ans << endl;
    }
    return 0;
}
