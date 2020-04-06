class Solution {
public:
    int numSteps(string s) {
        if(s.size() == 1)
            return 0;

        int count = 0;
        if(s[(int)s.size() - 1] == '0'){
            while(s[s.size() - 1] == '0'){
                cout << s << endl;
                s.pop_back();
                count++;
            }
        }else{
            count++;
            while(s.size() > 0 && s[(int)s.size() - 1] == '1'){
                s.pop_back();
                count++;
            }
            if(s.size() == 0)
                return count;

            s[s.size() - 1] = '1';
        }
        return count + numSteps(s);
    }
};