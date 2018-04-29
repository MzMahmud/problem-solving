/*
    //LOJ 1050 - Marbles
    Author: Moaz Mahmud
    Date  : 15 May,2017
    My Solution:
        the recurrence is simple
            prob(r,b):
                case 1:
                    red ball chosen, so problem reduces to prob(r-1,b-1)
                case 2:
                    blue ball chosen,so problem reduces to prob(r,b-2)

                prob(r-1,b-1) and prob(r-1,b-2) because Jim always removes blue ball.
                base case:
                    if r > b:
                        must loose,as blue ball is always decreasing.
                    if r = 0 and b != 0:
                        final pick must be blue so must win (prob = 1.0)
                    if r = 0 and b = 0:
                        logically its 1.0
    END :D :D
*/
#include <cstdio>
#define SIZE 502

using namespace std;

double dp[SIZE][SIZE];

double prob(int r,int b){
    if(r > b)   return (dp[r][b] = 0.0);
    if(!r &&!b) return (dp[r][b] = 1.0);
    if(!r && b) return (dp[r][b] = 1.0);

    if(dp[r][b] < 0.0){
        double red = ((r + 0.0)/(r + b))*prob(r-1,b-1);
        double blu = ((b + 0.0)/(r + b))*prob(r,b-2);
        dp[r][b] = red + blu;
    }
    return dp[r][b];
}


int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //double ans[SIZE][SIZE];
    for(int i = 0;i < SIZE;i++)
        for(int j = 0;j < SIZE;j++)
            dp[i][j] = -100.0;

    for(int i = 0;i < SIZE;i++)
        for(int j = 0;j < SIZE;j++)
            prob(i,j);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int r,b;
        scanf("%d%d", &r,&b);
        printf("Case %d: %.10lf\n",cn++,dp[r][b]);
    }
    return 0;
}


/*
//this is more memory and time efficient
//the earlier one is wasy to understnad
#include <cstdio>
#define SIZE 502

using namespace std;

int main() {
    double ans[SIZE][SIZE];
    ans[0][0] = ans[0][1] = 1.0;
    ans[1][1] = 0.5;
    ans[1][0] = 0.0;
    for(int r = 0;r < SIZE;r++){
        for(int b = 2;b < SIZE;b++){
    		     if(r > b)  ans[r][b] = 0.0;
    		else if(r == 0) ans[r][b] = 1.0;
    		else            ans[r][b] = ((r+0.0)/(r+b)*ans[r-1][b-1]) 
    									+ ((b+0.0)/(r+b)*ans[r][b-2]);
        }
    }

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int r,b;
        scanf("%d%d", &r,&b);
        printf("Case %d: %.10lf\n",cn++,ans[r][b]);
    }
    return 0;
}

*/
