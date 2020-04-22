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
    void print(){
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++)
                printf("%d ",mat[i][j]);
            printf("\n");
        }
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
matrix2D power(matrix2D a,int b){
    if(!b){matrix2D I(1,0,0,1);return I;}
    matrix2D x = power(a,b/2) ;
    x = (x*x);
    if(b&1) x = (x*a);
    return x;
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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout)

    matrix2D p(1,1,1,0),q(1,1,1,0);
    int a[2] = {1,0};
    int n = 10;
    q = power(p,n);
    q.print();
    q = power(p,n)%10;
    q.print();
    return 0;
}
