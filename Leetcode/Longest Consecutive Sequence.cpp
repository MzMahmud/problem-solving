class Solution {
    bool contains(const unordered_set<int> &set, int value) {
        return set.find(value) != end(set);
    }

  public:
    // O(n) Time | O(n) Space
    // solution explanation: https://youtu.be/P6RZZMu_maU
    int longestConsecutive(vector<int> &numbers) {
        unordered_set<int> uniqueNumbers(begin(numbers), end(numbers));
        int maxRangeLength = 0;
        for (int number : numbers) {
            if (contains(uniqueNumbers, number - 1)) {
                continue;
            }
            int currentRangeLength = 1;
            int rangeValue = number + 1;
            while (contains(uniqueNumbers, rangeValue)) {
                ++rangeValue;
                ++currentRangeLength;
            }
            maxRangeLength = max(maxRangeLength, currentRangeLength);
        }
        return maxRangeLength;
    }
};
