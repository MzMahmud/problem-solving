class Solution {
    void reverseWord(int startIndexInclusive, int endIndexInclusive, string &sentence) {
        for (;startIndexInclusive <= endIndexInclusive;++startIndexInclusive, --endIndexInclusive) {
            char temp = sentence[startIndexInclusive];
            sentence[startIndexInclusive] = sentence[endIndexInclusive];
            sentence[endIndexInclusive] = temp;
        }
    }
public:
    string reverseWords(string sentence) {
        for (int lastSpaceIndex = -1, currentIndex = 0; currentIndex <= sentence.size(); ++currentIndex) {
            if (currentIndex == sentence.size() || sentence[currentIndex] == ' ') {
                reverseWord(lastSpaceIndex + 1, currentIndex - 1, sentence);
                lastSpaceIndex = currentIndex;
            }
        }
        return sentence;
    }
};
