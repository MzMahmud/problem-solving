class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Set<String> dictionary = Set.of(words);
        List<String> concatenatedWords = new ArrayList<>();
        for (var word : words) {
            if (isWordBreakable(word, dictionary)) {
                concatenatedWords.add(word);
            }
        }
        return concatenatedWords;
    }

    // bottom up dp
    private boolean isWordBreakable(String string, Set<String> dictionary) {
        int len = string.length();
        boolean[] isBreakable = new boolean[len + 1];
        isBreakable[len] = true;
        for (int start = len - 1; start >= 0; --start) {
            int maxEnd = start == 0 ? len - 1 : len;
            // avoids full string to be considered as sub string
            // it done because the problem defines 2+ words concatenation to be breakable
            for (int end = start + 1; !isBreakable[start] && end <= maxEnd; ++end) {
                String substring = string.substring(start, end);
                isBreakable[start] = dictionary.contains(substring) && isBreakable[end];
            }
        }
        return isBreakable[0];
    }
}