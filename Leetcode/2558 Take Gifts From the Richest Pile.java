class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int gift : gifts) {
            pq.add((long) gift);
        }
        for (int i = 0; i < k && !pq.isEmpty(); i++) {
            long max = pq.poll();
            pq.add((long) Math.sqrt(max));
        }
        return pq.stream().mapToLong(n -> n).sum();
    }
}
