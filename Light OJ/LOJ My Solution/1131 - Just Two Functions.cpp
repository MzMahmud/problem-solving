/*
    LOJ 1131 - Just Two Functions
    Author: Moaz Mahmud
    Date  : 02 Nov,2017

    My Solution:
        A = {{a1,b1,0 ,0 ,0 ,c1},
             {1 ,0 ,0 ,0 ,0 ,0 },
             {0 ,1 ,0 ,0 ,0 ,0 },
             {0 ,0 ,c2,a2,b2,0 },
             {0 ,0 ,0 ,1 ,0 ,0 },
             {0 ,0 ,0 ,0 ,1 ,0 }};
        {F(n),F(n-1),F(n-2),g(n),g(n-1),g(n-2)} = A*{F(n-1),F(n-2),F(n-3),g(n-1),g(n-2),g(n-3)}
        Solving recurrence,
        {F(n),F(n-1),F(n-2),g(n),g(n-1),g(n-2)} = (A^(n-1))*{F(n-1),F(n-2),F(n-3),g(n-1),g(n-2),g(n-3)};n > 2
        Initials are given so F(n),g(n) is easily found.
        Done Matrix Exponentiation to find A^(n-2).

    END :D :D
*/
#include <cstdio>
#define DIM 6

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
        int a1,b1,c1;
        scanf("%d%d%d",&a1,&b1,&c1);

        int a2,b2,c2;
        scanf("%d%d%d",&a2,&b2,&c2);

        int mat[DIM][DIM] = {{a1,b1,0 ,0 ,0 ,c1},
                             {1 ,0 ,0 ,0 ,0 ,0 },
                             {0 ,1 ,0 ,0 ,0 ,0 },
                             {0 ,0 ,c2,a2,b2,0 },
                             {0 ,0 ,0 ,1 ,0 ,0 },
                             {0 ,0 ,0 ,0 ,1 ,0 }};
        int init[DIM];
        scanf("%d%d%d",&init[2],&init[1],&init[0]);
        scanf("%d%d%d",&init[5],&init[4],&init[3]);

        scanf("%d", &MOD);

        printf("Case %d:\n",cn++);
        int res[DIM][DIM],q;
        scanf("%d", &q);
        for(int i = 0;i < q;i++){
            int n,fn = 0,gn = 0;
            scanf("%d", &n);
                 if(n == 0) fn = init[2],gn = init[5];
            else if(n == 1) fn = init[1],gn = init[4];
            else if(n == 2) fn = init[0],gn = init[3];
            else{
                power(mat,n-2,res);
                for(int i = 0;i < DIM;i++){
                    fn += res[0][i]*init[i];
                    if(fn >= MOD) fn %= MOD;

                    gn += res[3][i]*init[i];
                    if(gn >= MOD) gn %= MOD;
                }
            }
            printf("%d %d\n",fn%MOD,gn%MOD);
        }
    }
    return 0;
}
