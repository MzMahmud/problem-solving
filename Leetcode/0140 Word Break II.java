class Solution {
    private List<String> sentences;

    public List<String> wordBreak(String s, List<String> wordDict) {
        sentences = new ArrayList<>();
        isValidSentence(0, s, new ArrayList<>(), new HashSet<>(wordDict));
        return sentences;
    }

    private boolean isValidSentence(int start, String string, List<String> words, Set<String> dict) {
        int len = string.length();
        if (start == len) {
            return true;
        }
        for (int end = start + 1; end <= len; ++end) {
            String suffix = string.substring(start, end);
            words.add(suffix);
            boolean isValid = dict.contains(suffix) && isValidSentence(end, string, words, dict);
            if (isValid) {
                sentences.add(String.join(" ", words));
            }
            words.remove(words.size() - 1);
        }
        return false;
    }
}
