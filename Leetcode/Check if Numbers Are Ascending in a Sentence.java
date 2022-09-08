class Solution {
    public boolean areNumbersAscending(String sentence) {
        Integer currentNumber = null;
        int prevNumber = -1;
        for (int i = 0; i < sentence.length(); ++i) {
            char c = sentence.charAt(i);
            if ('0' <= c && c <= '9') {
                currentNumber = (currentNumber == null ? 0 : currentNumber) * 10 + (c - '0');
            } else {
                if (currentNumber != null && prevNumber >= currentNumber) {
                    return false;
                }
                if (currentNumber != null) {
                    prevNumber = currentNumber;
                    currentNumber = null;
                }
            }
        }
        return currentNumber == null || prevNumber < currentNumber;
    }
}
