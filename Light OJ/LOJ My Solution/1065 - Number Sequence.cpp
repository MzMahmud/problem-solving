///Implementation with n x n

/*
    1065 - Number Sequence
    Author: Moaz Mahmud
    Date  : 02 Nov,2017

    My Solution:
        Matrix Exponentiation.
        This version is implemented for n*n matrix.
    END :D :D
*/
#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#define DIM 2

using namespace std;

int MOD;

//NOTATIONO [A] = matrix a; DIM = dimension
///operation :: result = [a]*[b]
///VERTY IMPORTANT :: never try to do multiply(a,b,a) or multiply(a,b,b)
///use different matrix for result
void multiply(int a[DIM][DIM],int b[DIM][DIM],int result[DIM][DIM]){
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
void copy(int to[DIM][DIM],int from[DIM][DIM]){
    for(int i = 0;i < DIM;i++)
        for(int j = 0;j < DIM;j++){
            to[i][j] = from[i][j];
            if(to[i][j] >= MOD) to[i][j] %= MOD;
        }

}
void print(int a[DIM][DIM]){
    for(int i = 0;i < DIM;i++){
        for(int j = 0;j < DIM;j++){
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
}
///operation :: [result] = pow([a],b)
///VERTY IMPORTANT :: never try to do power(a,b,a)
///use different matrix for result
void power(int a[DIM][DIM],int b,int result[DIM][DIM]){
    if(!b){
       int I[DIM][DIM] = {};
       for(int i = 0;i < DIM;i++) I[i][i] = 1;//making identity matrix
       copy(result,I);return;//like return 1
    }
    int x[DIM][DIM],y[DIM][DIM];
    power(a,b/2,x);//x = power(a,b/2)
    multiply(x,x,y);//y = x*x
    if(b&1){
        multiply(y,a,x);//x = y*a
        copy(y,x);//y = x;
    }
    copy(result,y);//result = y;like return result
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int a,b,n,m;
        scanf("%d%d",&a,&b);
        scanf("%d%d",&n,&m);
             if(m == 1) MOD = 10;
        else if(m == 2) MOD = 100;
        else if(m == 3) MOD = 1000;
        else if(m == 4) MOD = 10000;

        int initial[] = {b,a};

        int matrix[DIM][DIM] = {{1,1},
                                {1,0}};
        int result[DIM][DIM];

        power(matrix,n,result);
        int ans = result[1][0]*initial[0] + result[1][1]*initial[1];
        printf("Case %d: %d\n",cn++,ans % MOD);
    }
    return 0;
}

///Implementation with 2 x 2
/*
    1065 - Number Sequence
    Author: Moaz Mahmud
    Date  : 02 Nov,2017

    My Solution:
        Matrix Exponentiation.
    END :D :D
*/
#include <cstdio>
#include <cmath>

using namespace std;

//the whole purpose of this is to solve,F(n) = F(n-1) + F(n-2);F(0),F(1) given
//Let,A = {{1,1},{1,0}},b = {F(1),F(0)}
///F(n) = (A^n)*b
class matrix2D{
  public:
    int mat[2][2];
    matrix2D(int a,int b,int c,int d){
        mat[0][0] = a;mat[0][1] = b;
        mat[1][0] = c;mat[1][1] = d;
    }
    matrix2D operator=(matrix2D a){
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < 2;j++)
                mat[i][j] = a.mat[i][j];
    }
};
///this is done for finding (A^n)
matrix2D operator*(matrix2D a,matrix2D b){
    int w = a.mat[0][0]*b.mat[0][0] + a.mat[0][1]*b.mat[1][0];
    int x = a.mat[0][0]*b.mat[0][1] + a.mat[0][1]*b.mat[1][1];
    int y = a.mat[1][0]*b.mat[0][0] + a.mat[1][1]*b.mat[1][0];
    int z = a.mat[1][0]*b.mat[0][1] + a.mat[1][1]*b.mat[1][1];
    matrix2D n(w,x,y,z);
    return n;
}
///this is done for finding F(n) = (A^n)*b
int operator*(matrix2D a,int b[2]){return a.mat[1][0]*b[0] + a.mat[1][1]*b[1];}
///mod very element of [a] by m
matrix2D operator%(matrix2D a,int m){
    int w,x,y,z;
    w = a.mat[0][0]%m;x = a.mat[0][1]%m;
    y = a.mat[1][0]%m;z = a.mat[1][1]%m;
    matrix2D n(w,x,y,z);
    return n;
}
matrix2D power(matrix2D a,int b,int m){
    if(!b){matrix2D I(1,0,0,1);return (I%m);}
    matrix2D x = power(a,b/2,m) ;
    x = (x*x);
    x = x%m;
    if(b&1){x = (x*a);x = x % m;}
    return (x%m);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int a,b,n,m;
        scanf("%d%d",&a,&b);
        scanf("%d%d",&n,&m);
             if(m == 1) m = 10;
        else if(m == 2) m = 100;
        else if(m == 3) m = 1000;
        else if(m == 4) m = 10000;
        int initial[] = {b,a};

        matrix2D matrix(1,1,1,0);
        matrix = power(matrix,n,m);
        int ans = matrix*initial;
        printf("Case %d: %d\n",cn++,ans%m);
    }
    return 0;
}
