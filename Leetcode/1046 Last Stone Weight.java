class Solution {
    public int lastStoneWeight(int[] stones) {
        var heap = new PriorityQueue<Integer>(Comparator.reverseOrder());
        for (var stone : stones) {
            heap.add(stone);
        }
        while (heap.size() > 1) {
            int y = heap.poll(), x = heap.poll();
            if (x != y) {
                heap.add(y - x);
            }
        }
        return heap.isEmpty()? 0 : heap.peek(); 
    }
}
