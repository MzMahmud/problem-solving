class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int positionOfNewInterval = intervals.length;
        for(int i = 0;i < intervals.length; ++i) {
            if(newInterval[0] < intervals[i][0]) {
                positionOfNewInterval = i;
                break;
            }
        }

        List<int[]> afterInsert = new ArrayList<>();
        for(int i = 0;i < positionOfNewInterval; ++i) {
            afterInsert.add(intervals[i]);
        }

        insertInverval(afterInsert, newInterval);
        
        for(int i = positionOfNewInterval;i < intervals.length; ++i) {
            insertInverval(afterInsert, intervals[i]);
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
