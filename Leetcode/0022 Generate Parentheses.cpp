class Solution {
public:
    vector<string> generateParenthesis(int N) {
        vector<vector<string>> allParenthesis(N + 1,vector<string>());
        allParenthesis[0].push_back("");
        for(int n = 1;n <= N;n++){
            for(int k = 0;k < n;k++){
                const vector<string> &inside = allParenthesis[k];
                const vector<string> &right  = allParenthesis[n - 1 - k];
                for(const string &i : inside){
                    for(const string &r : right){
                        allParenthesis[n].push_back("(" + i + ")" +r);
                    }
                }
            }
        }
        return allParenthesis[N];        
    }
};