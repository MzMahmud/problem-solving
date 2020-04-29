class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        int len = 0;
        for(int r = 0;r < n;++r){
            for(int c = 0;c < m;++c){
                if(matrix[r][c] == '1'){
                    if(r == 0 or c == 0)
                        dp[r][c] = 1;    
                    else
                        dp[r][c] = 1 + min( min(dp[r][c-1],dp[r-1][c]), dp[r-1][c-1] );
                }
                len = max(len,dp[r][c]);
            }
        }
        return len*len;
    }
};