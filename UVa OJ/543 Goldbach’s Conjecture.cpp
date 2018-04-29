#include <bits/stdc++.h>
#define SIZE 1000003
#define getBit(n,pos)((bool)(n&(1<<pos)))
#define setBit(n,pos)(n = n|(1<<pos))

using namespace std;

int state[(SIZE/64)+2];

vector <unsigned int> nPrime;

void bitSieve(int n){
    nPrime.push_back(2);

    int pos,limit = sqrt(n*1.0)+2;
    for(int i = 3;i <= n;i+=2){
        pos = (i+1)/2;
        if( !getBit(state[pos>>5],(pos&31)) ){
            nPrime.push_back(i);
            if(i < limit){
                for(int j = i*i;j <= n;j+=(2*i)){
                    pos = (j+1)/2;
                    setBit(state[pos>>5],(pos&31));
                }
            }
        }
    }
}

int main(){
    bitSieve(SIZE);

    int n,k;
    scanf("%d", &n);
    while(n){
        for(int i = 1;i < nPrime.size() && nPrime[i] <= (n/2) ;i++){
            k = n - nPrime[i];
            int pos = (k+1)/2;
            if(!getBit(state[pos>>5],(pos&31))){
                printf("%d = %d + %d\n",n,nPrime[i],k);
                goto in;
            }
        }
        in:
        scanf("%d", &n);
    }
    return 0;
}
