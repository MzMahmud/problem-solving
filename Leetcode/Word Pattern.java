class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (words.length != pattern.length()) {
            return false;
        }
        Map<Character, String> characterToWord = new HashMap<>();
        Map<String, Character> wordToCharacter = new HashMap<>();
        for (int i = 0; i < pattern.length(); ++i) {
            String wordFromCharacter = characterToWord.get(pattern.charAt(i));
            Character characterFromWord = wordToCharacter.get(words[i]);
            if (wordFromCharacter == null && characterFromWord == null) {
                characterToWord.put(pattern.charAt(i), words[i]);
                wordToCharacter.put(words[i], pattern.charAt(i));
                continue;
            }
            boolean mappingNotMatched = !(Objects.equals(wordFromCharacter, words[i])
                                          && Objects.equals(characterFromWord, pattern.charAt(i)));
            if (mappingNotMatched) {
                return false;
            }
        }
        return true;
    }
}
