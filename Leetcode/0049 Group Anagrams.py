class Solution:
    def groupAnagrams(self, strs : List[str]) -> List[List[str]]:
        seen = {}
        for s in strs:
            char_count = [0 for _ in range(26)]
            for c in s:
                char_count[ord(c)-ord('a')] += 1
                
            char_count = str(char_count)
            
            if char_count not in seen:
                seen[char_count] = []
                
            seen[char_count].append(s)
            
        return [seen[s] for s in seen]