class Solution {
    public enum OccurrenceType {
        ANY, FIRST, LAST
    }

    public int binarySearch(int[] sortedNumbers, int target, OccurrenceType occurrenceType) {
        int lo = 0, hi = sortedNumbers.length - 1, occurrenceIndex = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (sortedNumbers[mid] == target) {
                if (occurrenceType == OccurrenceType.ANY) {
                    return mid;
                }
                occurrenceIndex = mid;
                if (occurrenceType == OccurrenceType.FIRST) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else if (sortedNumbers[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return occurrenceIndex;
    }
    
    public int[] searchRange(int[] sortedArray, int target) {
        int firstIndex = binarySearch(sortedArray, target, OccurrenceType.FIRST);
        int lastIndex = binarySearch(sortedArray, target, OccurrenceType.LAST);
        return new int[]{firstIndex, lastIndex};
    }
}
