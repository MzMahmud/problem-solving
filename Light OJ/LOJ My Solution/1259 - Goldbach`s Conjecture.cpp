#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define SIZE 10000002
bool isPrime[SIZE/2];
vector <int> nPrime;//Stores only odd primes is this problem

void primeSieve(int n)
{
    int i,j,limit = sqrt(n+0.0) + 2;
    for(i = 3;i <= n;i += 2){
        if( !isPrime[(i+1)/2] ){
            nPrime.push_back(i);
            if(i < limit){
                for(j = i*i;j <= n;j += (i*2) ){
                    isPrime[(j+1)/2] = 1;
                }
            }
        }
    }
}

int main()
{
    primeSieve(10000000);

    int T,cn = 1,n,way;

    scanf("%d",&T);
    while( T-- ){
        scanf("%d", &n);
        n == 4?way = 1:way = 0;
        for(int i = 0;nPrime[i] <= (n/2);i++){
            int k;
            k = n - nPrime[i];
            if( !isPrime[(k+1)/2] ){
                way++;
            }
        }
        printf("Case %d: %d\n",cn++,way);
    }

    return 0;
}


