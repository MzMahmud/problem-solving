class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> a_can_win(n + 1, false);
        a_can_win[1] = true;
        for(int i = 2;i <= n; ++i) {
            for(int k = 1; k * k <= i; ++k) {
                if(a_can_win[i - k * k] == false) {
                    a_can_win[i] = true;
                    break;
                }
            }
        }
        return a_can_win[n];
    }
};
