class Solution {
    public int nthUglyNumber(int n) {
        int i = 0;
        long uglyNumber = 0;
        PriorityQueue<Long> uglyNumbers = new PriorityQueue<>();
        uglyNumbers.add(1L);
        while (i < n) {
            uglyNumber = uglyNumbers.poll();
            ++i;
            for (var factor : List.of(2, 3, 5)) {
                long next = factor * uglyNumber;
                if (!uglyNumbers.contains(next)) {
                    uglyNumbers.add(next);
                }
            }
        }
        return (int) uglyNumber;
    }
}