/*
    //LOJ 1098 - A New Function
    Author: Moaz Mahmud
    Date  : 05 May,2017

    My Solution:
        an example
        numbers:  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        proper          2   2   2 3  2     2     2  3
        Divisors            3        5     4        5
                                           4

        So, the answer is
        CSOD(n) = SUM k = 2 to floor(n/2)  k(floor(n/k) - 1)
        But direct O(n) implementation results in TLE :(
        Now,observation: on floor(n/k)
            2 -> 7,7 -> 2,6 -> 2
            3 -> 5,5 -> 3,4 -> 3
        as any number n has divisor  <= sqrt(n)
        this would be true,
        for i = 2 to floor(sqrt(n)):
            if a = floor(n/i)
               the for integers b( = floor(n/(i+1)) + 1) to a
               floor(n/b) = i;
            So,the sum can be found in O(sqrt(n)) :D :D
            ans = ans + (a-1)*i + (i-1)(b+(b+1)+(b+2)+...+a)
            (b+(b+1)+(b+2)+...+a) = a(a+1)/2 - b(b-1)/2

            **special case:: if i == a then ans = ans + (a-1)*i;

        FINALLY CSOD(n) = ans;
    END
*/

#include<cstdio>
#include<cmath>

using namespace std;

int main() {
    freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        long long n,ans = 0,a,b;
        scanf("%lld", &n);
        long long sroot = sqrt(n*1.0);
        for(long long i = 2;i <= sroot;i++){
            a = (n/i);
            b = (n/(i+1)) + 1;
            if(i != a) ans = ans + (a-1)*i + (i-1)*(( a*(a+1) - b*(b-1) )/2);
            else       ans = ans + (a-1)*i ;
        }
        printf("Case %d: %lld\n",cn++,ans);
    }
    return 0;
}
