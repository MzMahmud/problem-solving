class Solution {
    public int removeDuplicates(int[] nums) {
        int insertPos = 0;
        for (int i = 1; i < nums.length; ++i) {
            if(nums[insertPos] != nums[i]) {
                nums[++insertPos] = nums[i];
            }
        }
        return insertPos + 1;
    }
}
