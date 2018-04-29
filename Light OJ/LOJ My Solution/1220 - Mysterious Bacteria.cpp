/*
ALGO:
    x = b^p
    p has to be maximized.
    now for the prime factorized form of x
    x = p1^a1.p2^a2...pn^an
    p would be gcd of the powers.
    but if x is negative then p cant be even.
    so the gcd must be 2 free.
*/
#include <bits/stdc++.h>
#define getBit(n,pos)((bool)(n&(1<<pos)))
#define setBit(n,pos)(n = n|(1<<pos))
#define SIZE 65540

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



int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}

int main(){
    bitSieve(SIZE);
    //freopen("in.txt","r",stdin);
    int T,cn = 1;
    cin >> T;
    while(T--){
        int x,p,ans = 0;//ans must be initialized by 0.As gcd(0,a) = a
        bool neg = false;
        cin >> x;
        if(x < 0){
            neg = true;
            x = abs(x);
        }
        for(int i = 0;nPrime[i]*nPrime[i] <= x && i < nPrime.size();i++){
            p = 0;
            while( !(x%nPrime[i]) ){
                x /= nPrime[i];
                p++;
            }
            if(p == 1) {ans = 1;break;}//if any power is 1 then gcd must be one
            else if(p)  ans = gcd(ans,p);
        }
        if(x != 1) ans = 1;
        //if x is not 1,that means it has a prime with power 1.So ans = 1
        if(neg){
            while(!(ans%2))
                ans /= 2;
        }//if x is negative ans is 2 freed
        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}
