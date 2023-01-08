class Solution:
    # start from beginning and slide window.
    # if current char is found, move start after last time current char is seen.
    # after moving start [start,current] is guaranteed to have unique chars.
    # calculate and update max_length.
    # record current char's latest occurrence.
    
    def lengthOfLongestSubstring(self, s: str) -> int:
        start, max_length = 0, 0
        seen_at_index = {}
        for current, char in enumerate(s):
            if char in seen_at_index:
                start = max(start, seen_at_index[char] + 1)
            max_length = max(max_length, current - start + 1)
            seen_at_index[char] = current
        return max_length
    
