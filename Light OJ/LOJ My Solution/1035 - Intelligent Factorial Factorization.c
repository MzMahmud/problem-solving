#include <stdio.h>
#include <math.h>

int primes[25];//Stores all primes < 100 in it

int is_prime(int );//Check is it a prime.Used to store primes in primes[]
int power_counter(int ,int );//For every primes < n counts their power

int main()
{
    //freopen("Input.txt","rt",stdin);
    //freopen("Output.txt","wt",stdout);

    int prime_power[25];//Used for saving primes power
    int t,c=1,n,i,j,k = 0;

    primes[0] = 2;
    for(i = 3;i < 100;i+= 2){
        if(is_prime(i) == 1)
            primes[++k] = i;
    }//Stores all primes < 100 in primes[]

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i = 0;i < 25;i++)
            prime_power[i] = power_counter(n,primes[i]);
        for(i = 24;i >= 0 ; i--){
            if(primes[i] <= n)
                break;
        }//**(1). Finds the last index of prime < n.Done for printing properly.

        printf("Case %d: %d =",c++,n);
        for(j=0;j < i;j++){
            if(prime_power[j] != 0)
                printf(" %d (%d) *",primes[j],prime_power[j]);
        }
        printf(" %d (%d)\n",primes[i],prime_power[i]);
        //Printed last prime according to value of i from **(1)
        k = 0;
    }
    return 0;
}

int is_prime(int n)
{
    int i,root;
    root = sqrt(n);
    if(n % 2 == 0)
        return 0;
    for(i = 3;i <= root;i = i + 2){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int power_counter(int n,int m)
{
    int i = 0,k = m;
    while(k <= n){
        i = i + (n/k);
        k = k*m;
    }
    return i;
}
