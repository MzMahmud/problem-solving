class Solution {
    public int minFlipsMonoIncr(String string) {
        int numberOf1s = 0, minFlips = 0;
        for(int i = 0;i < string.length(); ++i) {
            if(string.charAt(i) == '0') {
                minFlips = Math.min(numberOf1s, minFlips + 1);
            } else {
                ++numberOf1s;
            }
        }
        return minFlips;
    }
}
