// Uva 988

#include <iostream>
#include <vector>

using namespace std;

long long way(int curr, const vector<vector<int>> &nodes,
			  vector<long long> &dp) {

    if (nodes[curr].size() == 0)
        return dp[curr] = 1;

    if (dp[curr] < 0) {
        dp[curr] = 0;
        for (int i = 0; i < nodes[curr].size(); i++)
            dp[curr] += way(nodes[curr][i], nodes, dp);
    }
    return dp[curr];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	int n;
    bool first = true;
	while (cin >> n) {
        vector<vector<int>> nodes(n);
        vector<long long> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = (long long) -1;

            int c;
            cin >> c;
            while (c--) {
                int val;
                cin >> val;
                nodes[i].push_back(val);
            }
        }
		if(!first)
			cout << endl;
		cout << way(0, nodes, dp);
		first = false;
    }
    return 0;
}