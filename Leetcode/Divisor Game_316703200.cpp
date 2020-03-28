class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N + 1];
        dp[1] = false;
        
        for(int n = 2;n <= N;n++){
            bool a_won = false;
            for(int d = 1;d*d <= n;d++){
                if(a_won) break;
                
                if(!(n % d)){
                    a_won = a_won | !(dp[n - d]);
                    
                    if(d != 1 && d != (n / d))
                        a_won = a_won | !(dp[n - (n/d)]);
                }
            }
            dp[n] = a_won;
        }
        
        return dp[N];
    }
};
