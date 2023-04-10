right_to_left_map = { ')': '(', '}': '{', ']': '[' }

class Solution:
    def isValid(self, s):
        stack = []
        for char in s:
            if char in ['(', '{', '[']:
                stack.append(char)
                continue 
            if len(stack) == 0 or stack.pop() != right_to_left_map[char]:
                return False
        return len(stack) == 0
