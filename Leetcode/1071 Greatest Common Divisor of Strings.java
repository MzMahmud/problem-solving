class Solution {
    // key idea of the problem is that if gcd string exists it must be of gcd of the length
    // clever solution. O(m + n) time
    // the clever thing is cheking if gcd string does not exists by checking a + b == b + a
    // after the check is done the gcd must be a substring of gcd length 
    public String gcdOfStrings(String a, String b) {
        boolean hasNoGcdString = !(a + b).equals(b + a); // O(m + n) time
        if (hasNoGcdString) {
            return "";
        }
        int g = gcd(a.length(), b.length()); // < O(m + n) time
        return a.substring(0, g); // O(min(m + n)) time
    }

    // this solution uses the idea that gcd string must be of gcd length but checks whather gcd length string divides both 
    // O(m + n) time
    // because isDivisor(gcdCandidate, a) && isDivisor(gcdCandidate, b) runs in O(m + n) time
    // all other operations run in less time
    public String gcdOfStrings(String a, String b) {
        int g = gcd(a.length(), b.length()); // < O(m + n) time
        var gcdCandidate = a.substring(0, g);
        if (isDivisor(gcdCandidate, a) && isDivisor(gcdCandidate, b)) { // O(m + n) time
            return gcdCandidate;
        }
        return "";
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private boolean isDivisor(String divisor, String dividend) {
        int divisorLength = divisor.length();
        if (divisorLength == 0) {
            return dividend.length() == 0;
        }
        int i = 0;
        for (; i < dividend.length(); ++i) {
            char dividendCharI = dividend.charAt(i);
            char divisorCharI = divisor.charAt(i % divisorLength);
            if (dividendCharI != divisorCharI) {
                return false;
            }
        }
        return i % divisorLength == 0;
    }
}