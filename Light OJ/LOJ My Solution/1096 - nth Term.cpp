/*
    1096 - nth Term
    Author: Moaz Mahmud
    Date  : 02 Nov,2017

    My Solution:
        A = {{a,0,b,1},
             {1,0,0,0},
             {0,1,0,0},
             {0,0,0,1}};
        {F(n),F(n-1),F(n-2),c} = A*{F(n-1),F(n-1),F(n-3),c}
        Solving recurrence,
        {F(n),F(n-1),F(n-2),c} = (A^(n-2))*{F(2),F(1),F(0),c}; for all n > 2.
        Given {F(2),F(1),F(0),c} = {0,0,0,c}.
        F(n) = (A^(n-1))[0][3]*c;
        Done Matrix Exponentiation to find A^(n-1).

    END :D :D
*/
#include <cstdio>
#include <cmath>
#define DIM 4
#define MOD 10007

using namespace std;



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
        int n,a,b,c;
        scanf("%d%d%d%d",&n,&a,&b,&c);
        int mat[DIM][DIM] = {{a,0,b,1},
                             {1,0,0,0},
                             {0,1,0,0},
                             {0,0,0,1}};
        int res[DIM][DIM],ans;
        if(n <= 2) ans = 0;
        else{
            power(mat,n-2,res);
            ans = res[0][3]*c;
        }
        printf("Case %d: %d\n",cn++,ans%MOD);
    }
    return 0;
}
