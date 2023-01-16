class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        boolean isInserted = false;
        List<int[]> afterInsert = new ArrayList<>();
        for(int i = 0;i <= intervals.length; ++i) {
            boolean canBeInserted = !isInserted && (i == intervals.length || newInterval[0] < intervals[i][0]);
            if(canBeInserted) {
                insertInverval(afterInsert, newInterval);
                isInserted = true;
                --i;
            } else if(i < intervals.length) {
                if(isInserted) {
                    insertInverval(afterInsert, intervals[i]);
                } else {
                    afterInsert.add(intervals[i]);
                }
            }
        }
        return afterInsert.toArray(new int[0][]);
    }

    private boolean isNotOverlapping(int[] a,int[] b) {
        return a[1] < b[0] || b[1] < a[0];
    }

    private void insertInverval(List<int[]> sortedIntervals, int[] interval) {
        if(sortedIntervals.isEmpty()) {
            sortedIntervals.add(interval);
            return;
        }
        var lastInterval = sortedIntervals.get(sortedIntervals.size() - 1);
        if(isNotOverlapping(interval, lastInterval)) {
            sortedIntervals.add(interval);
            return;
        }
        lastInterval[1] = Math.max(lastInterval[1], interval[1]); 
    }
}
