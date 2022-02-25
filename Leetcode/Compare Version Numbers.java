class Solution {
    public int compareVersion(String version1, String version2) {
        String[] version1Arr = version1.split("\\.");
        String[] version2Arr = version2.split("\\.");
        int maxSize = Math.max(version1Arr.length, version2Arr.length);
        for(int i = 0;i < maxSize; ++i) {
            int a = i < version1Arr.length ? Integer.parseInt(version1Arr[i]) : 0;
            int b = i < version2Arr.length ? Integer.parseInt(version2Arr[i]) : 0;
            if(a != b) {
                return a < b ? -1 : 1;
            }
        }
        return 0;
    }
}
