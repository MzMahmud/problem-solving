public class Solution {
    private void reverseWord(int startIndexInclusive, int endIndexInclusive, StringBuilder reversedWordSentence) {
        for (; startIndexInclusive <= endIndexInclusive; ++startIndexInclusive, --endIndexInclusive) {
            char temp = reversedWordSentence.charAt(startIndexInclusive);
            reversedWordSentence.setCharAt(startIndexInclusive, reversedWordSentence.charAt(endIndexInclusive));
            reversedWordSentence.setCharAt(endIndexInclusive, temp);
        }
    }

    public String reverseWords(String sentence) {
        StringBuilder reversedWordSentence = new StringBuilder(sentence);
        for (int lastSpaceIndex = -1, currentIndex = 0; currentIndex <= sentence.length(); ++currentIndex) {
            if (currentIndex == sentence.length() || sentence.charAt(currentIndex) == ' ') {
                reverseWord(lastSpaceIndex + 1, currentIndex - 1, reversedWordSentence);
                lastSpaceIndex = currentIndex;
            }
        }
        return reversedWordSentence.toString();
    }
}
