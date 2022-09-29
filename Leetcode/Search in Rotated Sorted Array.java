class Solution {
    /* Notice that in any rotated sorted array a,
     * if a[lo] <= a[mid] -> a[lo...mid] is sorted
     * else               -> a[hi...mid] is sorted
     * Now if a[lo...mid] is sorted and target is not in the interval [a[lo], a[hi]]
     *        then target can not be in that part of the array. This eliminates half of the array.
     * Similarly, if target is not in the interval [a[mid], a[lo]] eliminates that part of the array.
     * This cuts the input size by half everytime, which leads to O(lg n) time.
     **/
    public int search(int[] rotatedSortedArray, int target) {
        int lo = 0, hi = rotatedSortedArray.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (rotatedSortedArray[mid] == target) {
                return mid;
            }
            if (rotatedSortedArray[lo] <= rotatedSortedArray[mid]) {
                if (isBetween(target, rotatedSortedArray[lo], rotatedSortedArray[mid])) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (isBetween(target, rotatedSortedArray[mid], rotatedSortedArray[hi])) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }

    private boolean isBetween(int target, int low, int high) {
        return (low <= target) && (target <= high);
    }
}
