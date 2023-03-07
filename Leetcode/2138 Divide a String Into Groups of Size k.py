class Solution:
    def divideString(self, s, k, fill):
        mod = len(s) % k
        if mod != 0:
            s += fill * (k - mod)
        divided = []
        for i in range(0, len(s), k):
            divided.append(s[i:(i+k)])
        return divided
