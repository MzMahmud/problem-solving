class Solution {
    vector<vector<int>> dp;
    string a,b;
public:
    int longestCommonSubsequence(string text1, string text2) {
        a = text1,b = text2;
        int n = a.length();
        int m = b.length();
        dp = vector<vector<int>>(n + 1,vector<int>(m + 1,-1));
        return lcs(n-1,m-1);
    }
    
    int lcs(int i,int j){
        if(i < 0 or j < 0) return 0;
        
        if(dp[i][j] < 0){
            if(a[i] == b[j]) dp[i][j] = 1 + lcs(i - 1,j - 1);
            else                 dp[i][j] = max(lcs(i - 1,j),lcs(i,j - 1));
        }
        return dp[i][j];
    }
};