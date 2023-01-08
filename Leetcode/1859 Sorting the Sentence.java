class Solution {
    record WordIndex(String word, int index) {}
    
    public String sortSentence(String sentence) {
        TreeSet<WordIndex> sortedWords = new TreeSet<>(Comparator.comparingInt(WordIndex::index));
        StringBuilder wordBuilder = new StringBuilder();
        int indexBuilder = 0, length = sentence.length();
        for (int i = 0; i <= length; ++i) {
            char letter = 0;
            boolean hasWordEnded = (i == length) || (letter = sentence.charAt(i)) == ' ';
            if (hasWordEnded) {
                if (!wordBuilder.isEmpty()) {
                    sortedWords.add(new WordIndex(wordBuilder.toString(), indexBuilder));
                    indexBuilder = 0;
                    wordBuilder = new StringBuilder();
                }
            } else if (Character.isDigit(letter)) {
                indexBuilder = indexBuilder * 10 + letter - '0';
            } else {
                wordBuilder.append(letter);
            }
        }
        return sortedWords.stream()
                          .map(WordIndex::word)
                          .collect(Collectors.joining(" "));
    }
}
