class Solution {
    public boolean wordBreak(String string, List<String> wordDict) {
        Set<String> dictionary = new HashSet<>(wordDict);
        Boolean[] cache = new Boolean[string.length() + 1];
        return isWordBreakable(0, string, dictionary, cache);
    }

    private boolean isWordBreakable(int startIndex, String string, Set<String> dictionary, Boolean[] cache) {
        if (cache[startIndex] != null) {
            return cache[startIndex];
        }
        if (startIndex == string.length()) {
            return cache[startIndex] = true;
        }
        for (int substrEnd = startIndex + 1; substrEnd <= string.length(); ++substrEnd) {
            String substring = string.substring(startIndex, substrEnd);
            boolean isBreakable = dictionary.contains(substring)
                                  && isWordBreakable(substrEnd, string, dictionary, cache);
            if (isBreakable) {
                return cache[startIndex] = true;
            }
        }
        return cache[startIndex] = false;
    }
}