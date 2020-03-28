class Solution {
public:
    int numSquares(int n) {
        vector<int> way(n + 1);
        way[0] = 0;
        way[1] = 1;
        for(int num = 2;num <= n;num++){
            way[num] = INT_MAX;
            for(int i = 1;i*i <= num;i++){
                way[num] = min(way[num],1 + way[num - i*i]);
            }
        }
        return way[n];
    }
};
