class Solution {
public:
    string reverseVowels(string s) {
        int i = 0,j = s.size() - 1;
        while(i < j){
            if(is_vowel(s[i]) && is_vowel(s[j])){
                swap(s[i],s[j]);
                i++,j--;   
            }
            else if(is_vowel(s[i]))
                j--;
            else if(is_vowel(s[j]))
                i++;
            else
                i++,j--;
        }
        return s;
    }
    
    bool is_vowel(char c){
        if('A' <= c && c <= 'Z')
            c = 'a' + c - 'A';
        
        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
};
