class Solution {
    public boolean check(int[] a) {
        int inversionCount = 0,n = a.length;
        for(int i = 0;i < n;++i) {
            if(a[i] > a[(i + 1) % n]) {
                ++inversionCount;
            }
        }
        return inversionCount <= 1;
    }
}
