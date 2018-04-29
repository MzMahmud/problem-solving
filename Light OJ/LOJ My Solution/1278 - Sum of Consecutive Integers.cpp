#include <bits/stdc++.h>
#define SIZE 10000002
#define getBit(n,pos)((bool)(n&(1<<pos)))
#define setBit(n,pos)(n = n|(1<<pos))

using namespace std;

using namespace std;

int state[(SIZE/64)+2];
vector <unsigned int> nPrime;
void bitSieve(int n){
    nPrime.push_back(2);
    int pos,limit = sqrt(n*1.0)+2;
    for(int i = 3;i <= n;i+=2){
        pos = (i+1)/2;
        if( !getBit( state[pos>>5],(pos&31) ) ){
            nPrime.push_back(i);
            if(i < limit){
                for(int j = i*i;j <= n;j+=(2*i)){
                    pos = (j+1)/2;
                    setBit( state[pos>>5],(pos&31) );
                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    bitSieve(SIZE);

    int T,cn = 1,ans,p;
    long long n,i,a;

    scanf("%d", &T);
    while(T--){
        scanf("%lld",&n);

        while( !(n % 2) )
            n /= 2;
        //as odd divisor is needed all power of 2 is taken away

        ans = 1,p = 0;
        for(i = 1;nPrime[i]*nPrime[i] <= n;i++){
            if(i > (nPrime.size() - 1) ) break;
            p = 0;
            while( n % nPrime[i] == 0 ){
                p++;
                n /= nPrime[i];//the power of nPrime[i]
            }
            ans *= (p+1);
        }
        if( n != 1 ) ans *= 2;
        //if the number does not end in 1 that means is a prime whose power is 1

        printf("Case %d: %lld\n",cn++,ans-1);
    }

    return 0;
}
