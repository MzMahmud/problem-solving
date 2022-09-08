class Solution {
public:
    bool areNumbersAscending(string sentence) {
        int prevNumber = -1, currentNumber = 0;
        bool hasCurrentNumber = false;
        for (int i = 0; i < sentence.size(); ++i) {
            if ('0' <= sentence[i] && sentence[i] <= '9') {
                hasCurrentNumber = true;
                currentNumber = currentNumber * 10 + (sentence[i] - '0');
            } else {
                if (hasCurrentNumber && prevNumber >= currentNumber) {
                    return false;
                }
                if (hasCurrentNumber) {
                    prevNumber = currentNumber;
                    hasCurrentNumber = false;
                    currentNumber = 0;
                }
            }
        }
        return !hasCurrentNumber || prevNumber < currentNumber;
    }
};
