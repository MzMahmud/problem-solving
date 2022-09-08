class Solution {
    public boolean check(int[] a) {
        int inversionCount = 0,n = a.length;
        for(int i = 1;i < n;++i) {
            if(a[i-1] > a[i]) {
                ++inversionCount;
            }
        }
        if(a[0] < a[n-1]) {
            ++inversionCount;
        }
        return inversionCount <= 1;
    }
}
