class Solution:
    def removeDuplicates(self, s, k):
        stack = []
        for c in s:
            if stack and stack[-1][0] == c:
                stack[-1][1] += 1
            else:
                stack.append([c, 1])
            if stack[-1][1] == k:
                stack.pop()
        return "".join(map(lambda cn: cn[0]*cn[1], stack))
