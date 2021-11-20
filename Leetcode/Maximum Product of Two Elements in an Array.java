class Solution {
    public int maxProduct(int[] nums) {
        Integer max1 = -1, max2 = -1;
        for(int num : nums) {
            if(max1 <= num) {
                max2 = max1;
                max1 = num;
            } else if(max2 < num && num < max1) {
                max2 = num;
            }
        }
        return (max1 - 1) * (max2 - 1);
    }
}