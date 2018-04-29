/*
    LOJ 1265 - Island of Survival
    Author: Moaz Mahmud
    Date  : 04 Dec,2017

    My Solution:
        Let p(d,t) be the probability of living with d deers ansd t tigers.
        Choosing two from (d+t+1) animals there are 5 cases,
        1) d-d : nothing happens,
                 probability = C(d,2)/C(d+t+1,2)*p(d,t)
        2) d-t : deer got killed,
                 probability = C(d,1)*C(t,1)/C(d+t+1,2)*p(d-1,t)
        3) t-m : man dies,
                 probability = 0
        4) t-t : both tigers die,
                 probability = C(t,2)/C(d+t+1,2)*p(d,t-2)
        5) d-m : two cases
                i) toKill,   probability = C(d,2)/C(d+t+1,2)*p(d-1,t)
               ii) notToKill,probability = C(d,2)/C(d+t+1,2)*p(d,t)
        Silpmifying gives,
        i) toKill    probability = (dt*p(d-1,t) + C(t,2)*p(d,t-2) + C(d,2)*p(d-1,t))/(C(d+t+1)-C(d,2))
       ii) nottoKill probability = dt*p(d-1,t) + C(t,2)*p(d,t-2))/(C(d+t+1)-C(d,2)-d)
       and so, p(d,r) = max(toKil,notToKill)
       base case:
            if t <= 0 100% survive
            if d == 0//only tigers left
                only choosing two tigers can save.So
                C(t,2)/C(t+1,2)*p(d,t-2)

      its an over lapping situation.So DP is applied.
    END :D :D
*/

#include <cstdio>
#define MAXN 1003
#define MAX(a,b) (a > b?a:b)

using namespace std;

double dp[MAXN][MAXN];
/*
double p(int d,int t){
    if(t <= 0) return dp[d][t] = 1.0;
    if(d == 0) return dp[d][t] =  (t-1.0)/(t+1)*p(d,t-2);
    if(dp[d][t] < 0){
        double k = (d+t+1)*(d+t)/2.0;//C(d+t+1,2)
        double m = k - d*(d-1)/2.0;//C(d+t+1,2) - C(d,2)
        double a = t*d*p(d-1,t) + t*(t-1)/2.0*p(d,t-2);
        double toKill    = ( a + d*p(d-1,t) )/m;
        double notToKill = ( a )/(m-d);
        dp[d][t] =  MAX(toKill,notToKill);
    }
    return dp[d][t];
}
*/
int main() {
    freopen("in.txt","r",stdin);
    //bottom up DP
    for(int d = 0;d <= 1000;d++){
        for(int t = 0;t <= 1000;t++){
                 if(t == 0 && d == 0) dp[d][t] = 1.0;
            else if(d == 0) dp[d][t] = (t-1.0)/(t+1)*(t < 2 ? 1.0 : dp[d][t-2]);
            else if(t == 0) dp[d][t] = 1.0;
            else{
                double k = (d+t+1)*(d+t)/2.0;//C(d+t+1,2)
                double m = k - d*(d-1)/2.0;//C(d+t+1,2) - C(d,2)
                double a = t*d*dp[d-1][t] + t*(t-1)/2.0*(t<2?1.0:dp[d][t-2]);
                double toKill    = ( a + d*dp[d-1][t] )/m;
                double notToKill = ( a )/(m-d);
                dp[d][t] =  MAX(toKill,notToKill);
            }
        }
    }

    int T,cn = 1;
    scanf("%d",&T);
    while (T--) {
        int t,d;
        scanf("%d%d",&t,&d);
        printf("Case %d: %.10lf\n",cn++,dp[d][t]);
    }
    return 0;
}

//A facinating solution
/*
Clue :
  * The number of deer is unimportant and is not needed for any calculation
  * If the number of tigers are odd then .. there is no way to make all the
    tigers disappear .. and so I will never be sure that if i try to leave
    the island i will not be killed .. so in this case the probability is zero(0);
  * If the number of tigers are even then the tigers will die by fighting each
    other .. And as the question says that we need to maximize the probability
    of my winning .. so I would assume that every day two tigers will die ..
    and i need to find the probability according to that ..

assume that there are T tigers .. and I am also there ..
So in total there are (T + 1) living creatures ..

so , in the first day the probability of choosing two tigers is ..

         |    T       (T - 1) |
Day(1) = |  ______  x _______ |
         |                    |
         |  (T + 1)      T    |


            (T - 1)
       =   _________      (simplifying the above equation )

            (T + 1)


so , choosing two tigers in the first day and also on the second day is ..

We need to understand that after the first day two of the tigers will die ..
so .. after the first day the number of tigers will be (T - 2) and as i am also
a creature so total number of animals in the second day will be (T - 1)


            [Day(1)]

            (T - 1)          (T - 3)
Day(2) =  ___________    x  __________

            (T + 1)          (T - 1)

if we run the same process until there are no tigers left the n I will win ..
and the expression will be like this .


              (T - 1)     (T - 3)   (T - 5)             5          3         1
Winning =     _______  x  _______ x _______ x ..... x _______ x _______ x _______

              (T + 1)     (T - 1)   (T - 3)             7          5         3

simplifying the equation we get


               1
Winning =   ________

            (T + 1)

:3 Such a simple solution ... :p


#include <cstdio>

using namespace std;

int main() {
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int t,d;
        scanf("%d%d",&t,&d);
        printf("Case %d: %.10lf\n",cn++,t%2?0.0:1.0/(t+1));
    }
    return 0;
}
*/