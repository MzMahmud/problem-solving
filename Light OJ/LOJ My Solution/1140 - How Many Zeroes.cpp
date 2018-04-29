/*
    //1140 - How Many Zeroes?
    Author : Moaz Mahmud
    Date   : 05 May,2017

    My Solution:
        I tried DP for long time :V But failed :(
        Finally got a pattern,actually observation ;)
        The last digit 0 occurs every 10 times and stays for 1 place
        like,1230,1240....
        again the second zero comes after 100 and stays for 10
        1000,1020,...
        So the apparent solution seems to be Sum k = 1 to floor(log(n)) floor(n/10^k)*10^(k-1)
        example,456789
        45678
        +45670
        +45600
        +45000
        +40000--->in fact its the solution.
        But there is a catch :V
        It only works when there is no 0 in the numbers. Like 4024 won't work.
        This is logical because it the 3rd zero does not hold 100 places but
        25 places,{00,01,02,...,24} for '40' and another zeros would be there
        because of '39','37',....So the zeros holds for 39*100+ 25 times ;)
        So a 100% Mathematical SOLUTION :D :D :D
    DONE :D :D
*/
#include<cstdio>

using namespace std;

long long zeros(long long n){
    if(n == 0) return 0;
    if(n < 0) return -1;
    //-1 because when taking from 0 to a an extra 1 has to added for 0   
    long long N = n,ans = 0, p = 10;
    while(p <= n){
        int d = N % 10;
        if(!d){//this means if the digit is zero
            ans += ((n/p) - 1)*(p/10);
            //here (p/10) is that 100 and ((n/p) - 1) is that 40-1=39 ;)
            ans += ( (n%(p/10)) + 1);
            //this is the extra stay,like the 24 + 1 in the example ;)
        }
        else ans += (n/p)*(p/10);
        p *= 10;
        N /= 10;
    }
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        printf("Case %d: %lld\n", cn++,zeros(b) - zeros(a-1));
    }
    return 0;
}
