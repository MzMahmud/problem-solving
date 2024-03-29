/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int lo = 1, hi = n;
        int firstBad = -1;
        while(lo  <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(isBadVersion(mid)) {
                firstBad = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return firstBad;
    }
}
