class Solution {
    record ValueIndex(int value, int index) {
    }

    static Comparator<ValueIndex> compareValueIndex =
            Comparator.<ValueIndex>comparingInt(vi -> vi.value)
                      .thenComparing(vi -> vi.index);

    public long findScore(int[] nums) {
        var pq = new PriorityQueue<>(compareValueIndex);
        for (int i = 0; i < nums.length; i++) pq.add(new ValueIndex(nums[i], i));
        var markedIndex = new HashSet<>();
        long score = 0;
        while (markedIndex.size() < nums.length && !pq.isEmpty()) {
            var valIndex = pq.poll();
            if (markedIndex.contains(valIndex.index())) continue;
            score += valIndex.value();
            markedIndex.add(valIndex.index() - 1);
            markedIndex.add(valIndex.index() + 1);
        }
        return score;
    }
}
