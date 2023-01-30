class Solution {
    public String decodeString(String s) {
        return decodeString(0, s).decoded;
    }

    public DecodedNextIndex decodeString(int start, String s) {
        StringBuilder decoded = new StringBuilder();
        int repeat = 0, i;
        for (i = start; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch == ']') {
                break;
            }
            if (ch == '[') {
                var decodedNextIndex = decodeString(i + 1, s);
                decoded.append(decodedNextIndex.decoded.repeat(repeat));
                i = decodedNextIndex.nextIndex;
                repeat = 0;
            } else if ('a' <= ch && ch <= 'z') {
                decoded.append(ch);
            } else if ('0' <= ch && ch <= '9') {
                repeat = repeat * 10 + ch - '0';
            }
        }
        return new DecodedNextIndex(decoded.toString(), i);
    }

    record DecodedNextIndex(String decoded, int nextIndex) {
    }
}