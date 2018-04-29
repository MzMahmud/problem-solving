#include <iostream>  
#include <cstdio>  
#include <cmath>  
  
#define size 1000010  
#define gamma 0.57721566490153286060651209008240243104215933593992

using namespace std;  

int main()  
{  
    double sum[size];
    sum[0]=0;  
    for(int i = 1;i < size;i++)  
        sum[i] = sum[i-1] + 1.0/i;  
    
    int T,cn = 1;  
    scanf("%d",&T);  
    while(T--){  
        int n;  
        scanf("%d",&n);
  
        printf("Case %d: ",cn++);  
        
        if(n < size)  
            printf("%.10lf\n",sum[n]);  
        else  
            printf("%.10lf\n",gamma + (log(n)+log(n+1))/2);  
    }  
    return 0;  
} 