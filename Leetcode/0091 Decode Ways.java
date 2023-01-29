class Solution {
    public int numDecodings(String string) {
        int[] cache = new int[string.length() + 1];
        Arrays.fill(cache, -1);
        return numDecodings(0, string, cache);
    }

    private static final Set<String> VALID_CODE;
    private static final int MAX_CODE_LENGTH;

    static {
        VALID_CODE = new HashSet<>();
        int maxCodeLength = 1;
        for (int i = 1; i <= 26; ++i) {
            var code = String.valueOf(i);
            maxCodeLength = Math.max(maxCodeLength, code.length());
            VALID_CODE.add(code);
        }
        MAX_CODE_LENGTH = maxCodeLength;
    }

    public int numDecodings(int start, String string, int[] cache) {
        if (cache[start] >= 0) {
            return cache[start];
        }
        if (start == string.length()) {
            return cache[start] = 1;
        }
        cache[start] = 0;
        int maxEnd = Math.min(start + MAX_CODE_LENGTH, string.length());
        for (int end = start + 1; end <= maxEnd; ++end) {
            String prefix = string.substring(start, end);
            if (VALID_CODE.contains(prefix)) {
                cache[start] += numDecodings(end, string, cache);
            }
        }
        return cache[start];
    }
}