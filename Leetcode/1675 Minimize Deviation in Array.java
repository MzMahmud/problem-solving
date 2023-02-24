import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public int minimumDeviation(int[] nums) {
        var maxHeap = new PriorityQueue<Integer>(Comparator.reverseOrder());
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            nums[i] = nums[i] % 2 == 1 ? nums[i] * 2 : nums[i];
            min = Math.min(min, nums[i]);
            maxHeap.add(nums[i]);
        }
        int deviation = Integer.MAX_VALUE;
        while (maxHeap.peek() % 2 == 0) {
            deviation = Math.min(deviation, maxHeap.peek() - min);
            int updatedMax = maxHeap.poll() / 2;
            min = Math.min(min, updatedMax);
            maxHeap.add(updatedMax);
        }
        deviation = Math.min(deviation, maxHeap.peek() - min);
        return deviation;
    }
}