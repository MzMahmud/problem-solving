class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>  matchingPair;
        matchingPair[')'] = '(';matchingPair['}'] = '{';
        matchingPair[']'] = '[';

        stack<char> opennings;

        for(int i = 0;i < s.size();i++){
            if(isOpenningBracket(s[i])){
                opennings.push(s[i]);
            }
            else{
                if(    opennings.empty()
                    || opennings.top() != matchingPair[s[i]])

                    return false;

                opennings.pop();
            }
        }

        return opennings.empty();
    }

    inline bool isOpenningBracket(char c){
        return c == '(' || c == '{' || c == '[';
    }
};

