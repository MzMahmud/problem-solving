// Optimized getIntervals with TreeMap
// keeps only the summary of the data stream
class SummaryRanges {
    private final TreeMap<Integer, Integer> intervals;

    public SummaryRanges() {
        intervals = new TreeMap<>();
    }

    // O(log n) time
    public void addNum(int value) {
        int start = value, end = value;
        
        var lowerInterval = intervals.floorEntry(value);
        if (lowerInterval != null) {
            int lowerEnd = lowerInterval.getValue();
            if (value <= lowerEnd) {
                return;
            }
            if (lowerEnd + 1 == value) {
                start = lowerInterval.getKey();
            }
        }
        
        var higherInterval = intervals.higherEntry(value);
        int valueNext = value + 1;
        if (higherInterval != null && valueNext == higherInterval.getKey()) {
            intervals.remove(valueNext);
            end = higherInterval.getValue();
        }
        intervals.put(start, end);
    }

    // O(n) time
    public int[][] getIntervals() {
        int[][] intervalsArr = new int[intervals.size()][];
        int i = 0;
        for (var interval : intervals.entrySet()) {
            intervalsArr[i++] = new int[]{interval.getKey(), interval.getValue()};
        }
        return intervalsArr;
    }
}

// keeps all the values of the data stream
// build the summary when getIntervals is called 
class SummaryRanges {
    private final TreeSet<Integer> values;

    public SummaryRanges() {
        values = new TreeSet<>();
    }

    // O(log n) time
    public void addNum(int value) {
        values.add(value);
    }

    // O(n) time
    public int[][] getIntervals() {
        List<int[]> intervalsList = new ArrayList<>();
        for (int value : values) {
            if (intervalsList.isEmpty()) {
                intervalsList.add(new int[] { value, value });
                continue;
            }
            var interval = intervalsList.get(intervalsList.size() - 1);
            if (interval[1] + 1 == value) {
                interval[1] = value;
            } else {
                intervalsList.add(new int[] { value, value });
            }
        }
        int[][] intervals = new int[intervalsList.size()][];
        for (int i = 0; i < intervals.length; ++i) {
            intervals[i] = intervalsList.get(i);
        }
        return intervals;
    }
}



/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(value);
 * int[][] param_2 = obj.getIntervals();
 */