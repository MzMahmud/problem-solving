right_to_left_map = {
    ')': '(',
    '}': '{',
    ']': '['
}

class Solution:
    def isValid(self, s):
        stack = []
        for char in s:
            is_left_parentheses = char in ['(', '{', '[']
            if is_left_parentheses:
                stack.append(char)
                continue 
            if len(stack) == 0 or stack[-1] != right_to_left_map[char]:
                return False
            stack.pop()
        return len(stack) == 0
