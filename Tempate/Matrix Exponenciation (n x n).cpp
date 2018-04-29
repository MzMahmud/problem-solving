#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#define DIM 3

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
            }
        }
    }
}
///operation :: [to]  = [from]
void copy(int to[DIM][DIM],int from[DIM][DIM]){
    for(int i = 0;i < DIM;i++)
        for(int j = 0;j < DIM;j++)
            to[i][j] = from[i][j];
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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a[DIM][DIM] = { {1,2,3},
                        {4,5,6},
                        {7,8,9}};
    int b[DIM][DIM] = { {1,0,0},
                        {0,1,0},
                        {0,0,1}};
    int c[DIM][DIM];
    //print(c);
    power(a,3,c);
    //multiply(a,a,c);//c = a*a;
    print(c);
    //multiply(a,c,b);//b = (a*a)*a
    //print(b);
    return 0;
}
