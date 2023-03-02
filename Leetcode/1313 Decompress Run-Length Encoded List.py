class Solution:
    def decompressRLElist(self, encoded):
        decoded = []
        for i in range(0, len(encoded)-1, 2):
            decoded.extend([encoded[i+1]] * encoded[i])
        return decoded
