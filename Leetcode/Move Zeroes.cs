public class Solution {
    public void MoveZeroes(int[] nums) {
        int lastNonZeroIndex = 0;
        for(int i = 0;i < nums.Length;i++){
            if(nums[i] != 0)
                nums[lastNonZeroIndex++] = nums[i];
        }
        while(lastNonZeroIndex != nums.Length)
            nums[lastNonZeroIndex++] = 0;
    }
}