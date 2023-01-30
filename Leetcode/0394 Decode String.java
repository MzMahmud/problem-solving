class Solution {
    public String decodeString(String s) {
        StringBuilder decoded = new StringBuilder();
        StringBuilder encoded = new StringBuilder();
        int repeat = 0, unpairedBraces = 0;
        boolean encodedStringStarted = false;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (encodedStringStarted) {
                if (ch == ']' && unpairedBraces == 1) {
                    String decodedInside = decodeString(encoded.toString());
                    decoded.append(decodedInside.repeat(repeat));
                    encoded = new StringBuilder();
                    encodedStringStarted = false;
                    repeat = 0;
                    unpairedBraces = 0;
                } else {
                    encoded.append(ch);
                    if (ch == '[') {
                        ++unpairedBraces;
                    } else if (ch == ']') {
                        --unpairedBraces;
                    }
                }
            } else {
                if ('a' <= ch && ch <= 'z') {
                    decoded.append(ch);
                } else if ('0' <= ch && ch <= '9') {
                    repeat = repeat * 10 + ch - '0';
                } else if (ch == '[') {
                    encodedStringStarted = true;
                    ++unpairedBraces;
                }
            }
        }
        return decoded.toString();
    }
}