#include <stdio.h>
#include <math.h>

#include <stdio.h>

long long int num(long long int n)
{
    int count = n % 2;

    while(n > 0){
          n = n >> 1;//Bit Right Shift by 1 place
          if(n % 2 == 1)
             count++;
                 //Counts Number of 1s in binary representation
    }
    return count;
}


long long int power(long long int a,long long int n)
{
    if(n == 0)
        return 1;

    return a*power(a,n-1);
}
int main()
{
    long long int n,ans;

    scanf("%I64d", &n);
    ans = power(num(n),n);
    printf("%I64d\n", ans);

    return 0;
}