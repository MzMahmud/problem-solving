class Solution {
    public static int singleNonDuplicate(int[] a) {
        int lo = 0, hi = a.length - 1;
        int mid = lo + (hi - lo) / 2;
        while (lo < hi) {
            if (a[mid - 1] != a[mid] && a[mid] != a[mid + 1]) {
                break;
            }
            int[] left, right;
            if (a[mid - 1] == a[mid]) {
                left = new int[] { lo, mid };
                right = new int[] { mid + 1, hi };
            } else {
                left = new int[] { lo, mid - 1 };
                right = new int[] { mid, hi };
            }
            int[] search = isOddSized(left) ? left : right;
            lo = search[0];
            hi = search[1];
            mid = lo + (hi - lo) / 2;
        }
        return a[mid];
    }

    public static boolean isOddSized(int[] interval) {
        return (interval[1] - interval[0] + 1) % 2 == 1;
    }
}