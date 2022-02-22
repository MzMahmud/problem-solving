class Solution {
    const int CHARACTER_SIZE = 26;
public:
    int titleToNumber(string columnTitle) {
        int columnNumber = 0;
        for(const char &letter : columnTitle) {
            columnNumber = columnNumber *  CHARACTER_SIZE + (letter - 'A' + 1);   
        }
        return columnNumber;
    }
};
