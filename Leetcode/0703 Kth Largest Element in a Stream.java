class KthLargest {
    private final PriorityQueue<Integer> kLargestElement;
    private final int k;

    public KthLargest(int k, int[] nums) {
        this.kLargestElement = new PriorityQueue<>();
        this.k = k;
        for (var num : nums) {
            add(num);
        }
    }

    public int add(int val) {
        if(kLargestElement.size() < k || kLargestElement.peek() <= val) {
            kLargestElement.add(val);
        }
        if(kLargestElement.size() > k) {
            kLargestElement.poll();
        }
        return kLargestElement.peek();
    }
}