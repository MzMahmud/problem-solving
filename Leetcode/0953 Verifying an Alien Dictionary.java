class Solution {
    // this solution is used to beat 100% 
    // DON'T Write this type of code in production!
    public boolean isAlienSorted(String[] words, String order) {
        int[] charToOrder = new int[order.length()];
        for (int i = 0; i < order.length(); ++i) {
            int charIndex = order.charAt(i) - 'a';
            charToOrder[charIndex] = i;
        }
        for (int wordIndex = 1; wordIndex < words.length; ++wordIndex) {
            var prevWord = words[wordIndex - 1];
            var currWord = words[wordIndex];
            int compared = Integer.compare(prevWord.length(), currWord.length());
            for (int i = 0; i < prevWord.length() && i < currWord.length(); ++i) {
                int prevWordI = prevWord.charAt(i) - 'a';
                int currWordI = currWord.charAt(i) - 'a';
                if (charToOrder[prevWordI] != charToOrder[currWordI]) {
                    compared = Integer.compare(charToOrder[prevWordI], charToOrder[currWordI]);
                    break;
                }
            }
            if (compared > 0) {
                return false;
            }
        }
        return true;
    }

    // this is much more readable code but beats 20% of java submission
    public boolean isAlienSorted(String[] words, String order) {
        var charComparator = getCharComparator(order);
        for (int i = 1; i < words.length; ++i) {
            int compared = compareString(words[i - 1], words[i], charComparator);
            if (compared > 0) {
                return false;
            }
        }
        return true;
    }

    private Comparator<Character> getCharComparator(String order) {
        int[] charToOrder = new int[order.length()];
        for (int i = 0; i < order.length(); ++i) {
            int charIndex = order.charAt(i) - 'a';
            charToOrder[charIndex] = i;
        }
        return Comparator.comparingInt(c -> charToOrder[c - 'a']);
    }

    private int compareString(String a, String b, Comparator<Character> charComparator) {
        for (int i = 0; i < a.length() && i < b.length(); ++i) {
            int compared = charComparator.compare(a.charAt(i), b.charAt(i));
            if (compared != 0) {
                return compared;
            }
        }
        return Integer.compare(a.length(), b.length());
    }
}