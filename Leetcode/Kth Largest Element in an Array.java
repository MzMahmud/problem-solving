class Solution {
    public int findKthLargest(int[] nums, int k) {    
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();
        
        for (int num : nums) {
            if (minHeap.size() < k)
                minHeap.add(num);
            else if (num > minHeap.peek()) {
                minHeap.add(num);
                if (minHeap.size() > k)
                    minHeap.poll();
            }
        }
        
        if(minHeap.size() < k)
            while(minHeap.size() > 1)
                minHeap.poll();

        return minHeap.peek();
    }
}

