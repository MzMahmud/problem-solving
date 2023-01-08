class Solution {
    /* start from beginning and slide window.
     * if current char is found, move start after last time current char is seen.
     * after moving start [start,current] is guaranteed to have unique chars.
     * calculate and update max_length.
     * record current char's latest occurrence.
     */
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> seenAtIndex = new HashMap<>();
        int maxLength = 0;
        for (int start = 0, current = 0; current < s.length(); ++current) {
            char c = s.charAt(current);
            if (seenAtIndex.containsKey(c)) {
                start = Math.max(start, seenAtIndex.get(c) + 1);
            }
            maxLength = Math.max(maxLength, current - start + 1);
            seenAtIndex.put(c, current);
        }
        return maxLength;
    }
}
