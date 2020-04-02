class Solution {
    public int thirdMax(int[] nums) {
    
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();
        
        for (int num : nums) {
            if(minHeap.contains(num))
                continue;
                
            if (minHeap.size() < 3)
                minHeap.add(num);
            else if (num > minHeap.peek()) {
                minHeap.add(num);
                if (minHeap.size() > 3)
                    minHeap.poll();
            }
        }
        
        if(minHeap.size() == 2)
            minHeap.poll();

        return minHeap.peek();
    }
}
