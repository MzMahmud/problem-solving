class Solution {
public:
    string reverseWords(string a) {
        int n = a.length();
        reverse(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            while (i < n && a[i] == ' ') i++;
            int j = i;
            while (j < n && a[j] != ' ') j++;
            reverse(a, i, j - 1);
            i = j;
        }
        return cleanSpace(a);
    }
    
    string cleanSpace(string &a) {
        int n = a.length(), i = 0;
        for (int j = 0; j < n; ) {
            while (j < n && a[j] == ' ') j++;
            while (j < n && a[j] != ' ') a[i++] = a[j++];
            while (j < n && a[j] == ' ') j++;
            if (j < n) a[i++] = ' ';
        }
        return a.substr(0, i);
    }

    void reverse(string &a, int i, int j) {
        for (; i < j; i++, j--) {
            char temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
};
