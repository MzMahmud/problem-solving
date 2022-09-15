class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        int n = changed.size();
        if (n % 2 == 1) {
            return {};
        }
        sort(changed.begin(), changed.end());
        vector<int> original;
        unordered_map<int, int> count;
        for (const auto &number : changed) {
            count[number]++;
        }
        for (const auto &number : changed) {
            if (count[number] == 0) {
                continue;
            }
            int doubled = number << 1;
            if (count[doubled] == 0) {
                return {};
            }
            original.push_back(number);
            count[number]--;
            count[doubled]--;
        }
        return original;
    }
};
