/*
My Soln is ANS = C(n,r)*P(n,r)
As P(n,r) = C(n,r)*r!
So ANS = C(n,r)*C(n,r)*r!
Now Just Coded it :D
*/

#include<stdio.h>

long long int Com[31][31],F[31],ans;
long long int C(int ,int);
long long int fact(int );

int main()
{
    //freopen("Input.txt","rt",stdin);
    //freopen("Output.txt","wt",stdout);
    int i,j,t,c = 1,n,k;

    for(i = 0;i < 31;i++){
        F[i] = -1;
        for(j = 0;j < 31;j++)
            Com[i][j] = -1;
    }

    scanf("%d", &t);

    while( t-- ){
        scanf("%d%d", &n,&k);
        if( k > n )
            ans = 0;
        else{
            ans = C(n,k);
            ans = ans*ans*fact(k);
        }
        printf("Case %d: %lld\n",c++,ans);
    }
    return 0;
}

long long int C(int n,int r)
{
    if(r > (n/2))
        r = n - r;

    if(r == 0){
        Com[n][r] = 1;
        return Com[n][r];
    }
    if(Com[n][r] == -1){
        Com[n][r] = C(n-1,r) + C(n-1,r-1);
        return Com[n][r];
    }
    else
        return Com[n][r];
}

long long int fact(int n)
{
    if(n == 0){
        F[n] = 1;
        return F[n];
    }
    if(F[n] == -1){
        F[n] = n*fact(n-1);
        return F[n];
    }
    else
        return F[n];
}
