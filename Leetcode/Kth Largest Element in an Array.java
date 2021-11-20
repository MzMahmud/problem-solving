class Solution {
    public Integer findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        for (int num : nums) {
            if (priorityQueue.isEmpty() || priorityQueue.size() < k || num > priorityQueue.peek())
                priorityQueue.add(num);
            if (priorityQueue.size() > k)
                priorityQueue.poll();
        }
        return priorityQueue.peek();
    }
}