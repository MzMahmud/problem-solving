class Solution {
    string hexMap = "0123456789abcdef";
public:
    string toHex(int number) {
        unsigned int n = number;
        string hex;
        int i = 0;
        do {
            int hexIndex = n & 15;
            hex.push_back(hexMap[hexIndex]);
            n >>= 4;
            ++i;
        } while(i < 8 and n != 0);
        reverse(begin(hex), end(hex));
        return hex;
    }
};