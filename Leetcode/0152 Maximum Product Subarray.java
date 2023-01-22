
 class Solution {
    public int maxProduct(int[] nums) {
        int maxProd = nums[0];
        int currMaxProd = nums[0], currMinProd = nums[0];
        for(int i = 1;i < nums.length;++i) {
            var possibleValues = List.of(nums[i], nums[i] * currMaxProd, nums[i] * currMinProd);
            currMaxProd = Collections.max(possibleValues);
            currMinProd = Collections.min(possibleValues);
            maxProd = Collections.max(List.of(maxProd, currMaxProd, currMinProd));
        }
        return maxProd;
    }
}      

