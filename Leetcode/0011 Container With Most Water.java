class Solution {
    /* Two Pointers Solution (O(n) time, O(1) space)
     * Start with the most wide container [0, n-1]
     * Leaving the smaller wall may increase the height but leaving the bigger never increase height
     * So compare two end point and move the lower end point index and continue until two pointers meet.
    **/
    public int maxArea(int[] heights) {
        int i = 0, j = heights.length - 1, maxArea = 0;
        while (i < j) {
            int width = j - i;
            if (heights[i] < heights[j]) {
                maxArea = Math.max(maxArea, heights[i] * width);
                ++i;
            } else {
                maxArea = Math.max(maxArea, heights[j] * width);
                --j;
            }
        }
        return maxArea;
    }
}
