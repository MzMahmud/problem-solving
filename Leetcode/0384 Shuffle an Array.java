class Solution {
    private int[] shuffled;
    private int[] original;
    private final Random random;

    public Solution(int[] nums) {
        original = nums;
        shuffled = original.clone();
        random = new Random();
    }
    
    public int[] reset() {
        return original.clone();
    }

    private int getRandomIndex(int length) {
        return random.nextInt(length);
    }

    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    public int[] shuffle() {
        for(int i = 0;i < shuffled.length; ++i) {
            swap(shuffled, i, getRandomIndex(shuffled.length));
        }
        return shuffled;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
