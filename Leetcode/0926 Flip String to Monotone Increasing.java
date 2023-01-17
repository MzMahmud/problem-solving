class Solution {
    /* lets consider flip(i) to be #flips to make langth i string valid.
     * now if i-th (0-based) character is 1 the no need to do anyting because adding
     * 1 at the end of any vaid monotonic string would preserve the order.
     * if i-th character is 0 then we have 2 options
     *     - take i length string (flip(i) flips) and flip 0 to 1 (1 flip)
     *     - flip all the ones that came before i and dont flip 0
     * flip(i + 1) = |> flip(i) if s[i] == '1'
     *               |> min(numberOf1s before i-th character, flip(i) + 1) otherwise
     */
    // O(n) time | O(1) space
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
    
    private Integer[][] cache;

    // O(n) time | O(n) space
    private int solveWithTwoStateDp(String s) {
        cache = new Integer[s.length() + 1][2];
        return solveWithTwoStateDp(s, 0, 0);
    }

    private int solveWithTwoStateDp(String s, int index, int lastChar) {
        if(cache[index][lastChar] != null) {
            return cache[index][lastChar];
        }
        if(index == s.length()) {
            return cache[index][lastChar] = 0;
        }
        boolean isCurrentZero = s.charAt(index) == '0';
        if(lastChar == 0) {
            cache[index][lastChar] = Math.min(
                solveWithTwoStateDp(s, index + 1, 0) + (isCurrentZero ? 0 : 1),
                solveWithTwoStateDp(s, index + 1, 1) + (isCurrentZero ? 1 : 0)
            );
        } else {
            cache[index][lastChar] =  solveWithTwoStateDp(s, index + 1, 1) + (isCurrentZero ? 1 : 0);
        }
        return cache[index][lastChar];
    }
}
