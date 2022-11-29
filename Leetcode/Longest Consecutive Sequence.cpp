class Solution {
  public:
    // O(n) Time | O(n) Space
    int longestConsecutive(vector<int> &numbers) {
        unordered_set<int> uniqueNumbers(begin(numbers), end(numbers));
        int maxRangeLength = 0;
        for (int number : numbers) {
            int rangeStart = number - 1;
            while (uniqueNumbers.find(rangeStart) != end(uniqueNumbers)) {
                --rangeStart;
                uniqueNumbers.erase(number);
            }
            int rangeEnd = number + 1;
            while (uniqueNumbers.find(rangeEnd) != end(uniqueNumbers)) {
                ++rangeEnd;
                uniqueNumbers.erase(number);
            }
            int currentRangeLength = rangeEnd - rangeStart - 1;
            maxRangeLength = max(maxRangeLength, currentRangeLength);
        }
        return maxRangeLength;
    }
};
