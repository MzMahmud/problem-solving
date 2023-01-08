class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int totalCost = 0, iceCreamsTaken = 0;
        for(int cost : costs) {
            int nextTotalCost = totalCost + cost;
            if(nextTotalCost > coins) {
                break;
            }
            totalCost = nextTotalCost;
            ++iceCreamsTaken;
        }
        return iceCreamsTaken;
    }
}
