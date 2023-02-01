class Solution {
    private static final Map<Character, Integer> charToValue = Map.of(
            'I', 1,
            'V', 5,
            'X', 10,
            'L', 50,
            'C', 100,
            'D', 500,
            'M', 1000
    );

    public int romanToInt(String romanNumber) {
        int value = 0;
        int lastCharValue = 0;
        for (int i = romanNumber.length() - 1; i >= 0; --i) {
            var charValue = charToValue.get(romanNumber.charAt(i));
            value += (charValue < lastCharValue ? -1 : 1) * charValue;
            lastCharValue = charValue;
        }
        return value;
    }
}