#include <bits/stdc++.h>
#define SIZE 1000000

using namespace std;

bool isPrime[SIZE/2];
//only the mark of odd numbers is kept so total size is SIZE/2
vector <unsigned int> nPrime;
void primeSieve(int n)
{
    nPrime.push_back(2);

    int limit = sqrt(n+0.0) + 2;
    for(int i = 3;i <= n;i += 2){
        if( !isPrime[(i+1)/2] ){
            nPrime.push_back(i);
            if(i < limit){
                for(int j = i*i;j <= n;j += (i*2) ){
                    isPrime[(j+1)/2] = 1;
                    /*all composites below sqrt(i) is canceled
                     *so started canceling from i*i
                     *j += (2*i) because j+=i would give an even.
                     */
                }
            }
        }
    }
}

/*NB: Bit Sieve is more memory efficient.
 *because sizeof(bool) is not 1 bit,but 1 byte
 *because computer can't point memory < 1 byte
 */

int main(){
    primeSieve(100);
    for(int i = 0;i < nPrime.size();i++)
        cout << nPrime[i] << " ";
    cout << endl << "#primes: " << nPrime.size();
    return 0;
}

