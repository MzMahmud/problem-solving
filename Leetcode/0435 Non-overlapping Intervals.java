class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[0]));
        
        int lastEnd = Integer.MIN_VALUE, removedInterval = 0;
        for (var interval : intervals) {
            boolean isOverlapping = interval[0] < lastEnd;
            if (isOverlapping) {
                lastEnd = Math.min(interval[1], lastEnd);
                ++removedInterval;
            } else {
                lastEnd = interval[1];
            }
        }
        return removedInterval;
    }
}