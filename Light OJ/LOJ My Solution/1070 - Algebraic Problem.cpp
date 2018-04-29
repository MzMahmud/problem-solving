/*
    1070 - Algebraic Problem
    Author: Moaz Mahmud
    Date  : 02 Nov,2017

    My Solution:
        May be this is my most favorite problem <3.
        I just love my solution. I think i would write it
        the solution in LaTeX.

    END :D :D
*/
#include <cstdio>
#define DIM 2

using namespace std;
typedef unsigned long long ull;

//NOTATIONO [A] = matrix a; DIM = dimension
///operation :: result = [a]*[b]
///VERTY IMPORTANT :: never try to do multiply(a,b,a) or multiply(a,b,b)
///use different matrix for result
void multiply(ull a[DIM][DIM],ull b[DIM][DIM],ull result[DIM][DIM]){
    for(ull i = 0;i < DIM;i++){
        for(ull j = 0;j < DIM;j++){
            result[i][j] = 0;
            for(ull k = 0;k < DIM;k++){
                result[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
}
///operation :: [to]  = [from]
void copy(ull to[DIM][DIM],ull from[DIM][DIM]){
    for(ull i = 0;i < DIM;i++)
        for(ull j = 0;j < DIM;j++){
            to[i][j] = from[i][j];
        }

}
void prull(ull a[DIM][DIM]){
    for(ull i = 0;i < DIM;i++){
        for(ull j = 0;j < DIM;j++){
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
}
///operation :: [result] = pow([a],b)
///VERTY IMPORTANT :: never try to do power(a,b,a)
///use different matrix for result
void power(ull a[DIM][DIM],ull b,ull result[DIM][DIM]){
    if(!b){
       ull I[DIM][DIM] = {};
       for(ull i = 0;i < DIM;i++) I[i][i] = 1;//making identity matrix
       copy(result,I);return;//like return 1
    }
    ull x[DIM][DIM],y[DIM][DIM];
    power(a,b/2,x);//x = power(a,b/2)
    multiply(x,x,y);//y = x*x
    if(b&1){
        multiply(y,a,x);//x = y*a
        copy(y,x);//y = x;
    }
    copy(result,y);//result = y;like return result
}

ull power(ull a,ull b)
{
    if (!b)  return (ull)1;
    ull x = power(a,b/2) ;
    x *= x;
    if(b&1) x *= a;
    return x ;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        ull p,q,n;
        scanf("%llu%llu%llu",&p,&q,&n);

        ull ans;
        if((p*p) == (4*q)){//this means a == b
            p /= ((ull)2);
            ans = 2*power(p,n);
        }else{//n the term of F(n) = pF(n-1) - qF(n2);F(0) = 2,F(1) = p
            ull initial[] = {p,2};
                 if(n == 0) ans = initial[1];
            else if(n == 1) ans = initial[0];
            else{
                ull matrix[DIM][DIM] = {{p,-q},
                                        {1,0}};
                ull result[DIM][DIM];
                power(matrix,n-1,result);
                ans = result[0][0]*initial[0] + result[0][1]*initial[1];
            }
        }
        printf("Case %d: %llu\n",cn++,ans);
    }
    return 0;
}
