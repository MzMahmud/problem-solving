class Solution {
  public:
    // O(n) Time | O(n) Space
    vector<int> countBits(int n) {
        vector<int> numberOfOnes(n + 1, 0);
        int offset = 0, nextPowerOfTwo = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == nextPowerOfTwo) {
                offset = nextPowerOfTwo;
                nextPowerOfTwo <<= 1;
            }
            numberOfOnes[i] = 1 + numberOfOnes[i - offset];
        }
        return numberOfOnes;
    }
};
