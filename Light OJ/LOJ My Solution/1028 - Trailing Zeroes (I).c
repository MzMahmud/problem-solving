#include <stdio.h>

int prime[500003] = {0};
int power[500003] = {0};

int main()
{
     int tc,cn = 1,i,j,k,isPrime = 1;
     long long int n,nod = 1;

     //Store Primes
     prime[0] = 2;
     for(i = 1;((2*i)+1) <= 1005;i++){
        if( prime[i] != 1 ){
            j = ((2*i) + 1);
            k = i + j;
            while( k < 500003){
                prime[k] = 1;
                k += j;
            }
        }
     }
     //End of Prime Storing

     scanf("%d", &tc);
     while( tc-- ){
          scanf("%lld", &n);

          isPrime = 1,nod = 1;//Initialization

          if( n == 1){
              nod = 1;
              goto end;
          }

          //Checks For 2 Divisibility
          power[0] = 0;
          while( n % prime[0] == 0 ){
               n = n/2;
               power[0]++;
               isPrime = 0;
          }
          nod = power[0] + 1;

          for( i = 1;i < 500003;i++){
                if( prime[i] == 1)
                    continue;

                power[i] = 0;
                if( n == 1)
                    break;

                isPrime = 1;
                k = (2*i) + 1;
                if( k > (int) sqrt(n) )
                    break;
                while( n % k == 0 ){
                    n = n/k;
                    power[i]++;
                    isPrime = 0;
                }
                nod = nod*(power[i] + 1);
          }
          if( isPrime == 1 )
              nod = nod*2;

          end:
              printf("Case %d: %lld\n",cn++,nod - 1);
     }
     return 0;
}
