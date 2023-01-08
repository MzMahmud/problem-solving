class Solution {
    private int maxLength, start, end;

    public String longestPalindrome(String string) {
        maxLength = start = end = 0;
        for (int i = 0; i < string.length(); ++i) {
            expandPalindromeAndUpdateMax(i, i, string);
            expandPalindromeAndUpdateMax(i, i + 1, string);
        }
        return string.substring(start, end);
    }

    private void expandPalindromeAndUpdateMax(int start, int end, String string) {
        while (0 <= start && end < string.length() && string.charAt(start) == string.charAt(end)) {
            --start;
            ++end;
        }
        int currentLength = end - start - 1;
        if (currentLength > this.maxLength) {
            this.maxLength = currentLength;
            this.start = start + 1;
            this.end = end;
        }
    }
}
