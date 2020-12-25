public class Solution {
    public int NumIdenticalPairs(int[] nums) {
        Dictionary<int,int> seen = new Dictionary<int,int>();
        int numGoodPairs = 0;
        foreach(int n in nums){
            if(!seen.ContainsKey(n)) seen[n] = 0;
            numGoodPairs += seen[n]; 
            seen[n]++;
        }
        return numGoodPairs;
    }
}