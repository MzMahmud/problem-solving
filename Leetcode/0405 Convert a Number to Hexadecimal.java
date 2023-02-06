class Solution {
    private static final char[] HEX_MAP = {
            '0', '1', '2', '3', '4', '5', '6', '7',
            '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    public String toHex(int number) {
        if (number == 0) {
            return "0";
        }
        StringBuilder hex = new StringBuilder();
        for (int i = 0; i < 8 && number != 0; ++i) {
            int hex_digit = number & 15;
            hex.append(HEX_MAP[hex_digit]);
            number >>>= 4;
        }
        return hex.reverse().toString();
    }
}
