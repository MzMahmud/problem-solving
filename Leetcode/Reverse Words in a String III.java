class Solution {
    private void copyWordInReverse(int startIndexInclusive, int endIndexExclusive,
                                   String s, StringBuilder reversedWordSentence) {
        for (int currentIndex = endIndexExclusive + 1;
             endIndexExclusive < startIndexInclusive;
             ++currentIndex, --startIndexInclusive
        ) {
            reversedWordSentence.setCharAt(currentIndex, s.charAt(startIndexInclusive));
        }
    }

    public String reverseWords(String s) {
        StringBuilder reversedWordSentence = new StringBuilder(s);
        for (int lastSpaceIndex = -1, currentIndex = 0; currentIndex <= s.length(); ++currentIndex) {
            if (currentIndex == s.length() || s.charAt(currentIndex) == ' ') {
                copyWordInReverse(currentIndex - 1, lastSpaceIndex, s, reversedWordSentence);
                if (currentIndex < s.length()) {
                    reversedWordSentence.setCharAt(currentIndex, ' ');
                    lastSpaceIndex = currentIndex;
                }
            }
        }
        return reversedWordSentence.toString();
    }
}
