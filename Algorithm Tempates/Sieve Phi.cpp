#include <bits/stdc++.h>
#define SIZE 1000000

using namespace std;
/*Euler Phi(n) = n \prod (1-1/p_i) = n \prod ((p_i-1)/p_i)
 *Phi(n) = number of co-prime integer of n below n.
 */
long long phi[SIZE];
bool mark[SIZE];
void sievePhi(int n)
{
    int i,j;

    phi[1]  = 1;
    mark[1] = 1;

    for(i = 2;i <= n;i++) phi[i] = i;
    //Phi(n) = n \prod ((p_i-1)/p_i),so all i are added in array

    for(i = 2;i <= n;i += 2){
        phi[i] = i/2;
        if(i != 2) mark[i] = 1;
    }//Every even number is a divisor of 2

    for(i = 3;i <= n; i+= 2){
        if( !mark[i] ){
            phi[i] = i - 1;
            for(j = 2*i; j <= n;j += i){
                mark[j] = 1;
                 phi[j] = phi[j]/i*(i-1);
                 /*\prod ((p_i-1)/p_i)
                  *here the division is done earlier to stop overflow.
                  *this won't create problem as i is a prime divisor of n.
                  */
            }
        }
    }
}

int main(){
    sievePhi(103);
    cout << phi[100];
    return 0;
}
