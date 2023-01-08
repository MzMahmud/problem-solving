# recurrsive dp
class Solution:
    dp = {}
    
    @staticmethod
    def min_cost_from(index : int,n : int,costs: List[int]) -> int:
        if index >= n:
            Solution.dp[index] = 0
            
        if index not in Solution.dp:
            one_step_cost = Solution.min_cost_from(index + 1,n,costs)
            
            two_step_cost = Solution.min_cost_from(index + 2,n,costs)
            
            cost = 0 if index < 0 else costs[index]
            
            Solution.dp[index] = cost + min(one_step_cost,two_step_cost)
        
        return Solution.dp[index] 
    
    def minCostClimbingStairs(self, costs: List[int]) -> int:
        Solution.dp = {}
        return Solution.min_cost_from(-1,len(costs),costs)


# iterative dp
class Solution:
    def minCostClimbingStairs(self, costs: List[int]) -> int:
        n = len(costs)
        for i in range(n - 1, -1, -1):
            one_step_cost = costs[i + 1] if (i + 1) < n else 0
            two_step_cost = costs[i + 2] if (i + 2) < n else 0   
            costs[i] = costs[i] + min(one_step_cost,two_step_cost) 
        return min(costs[0],costs[1])
        

#define MIN(a,b) ( ((a) < (b)) ? (a) : (b) )

class Solution {
public:
    int minCostClimbingStairs(vector<int>& costs) {
        int n = costs.size();
        for(int i = n - 1;i >= 0;i--){
            int one_step_cost = (i + 1) < n ? costs[i + 1] : 0;
            int two_step_cost = (i + 2) < n ? costs[i + 2] : 0;   
            costs[i] = costs[i] + MIN(one_step_cost,two_step_cost);
        }
        return MIN(costs[0],costs[1]);
    }
};