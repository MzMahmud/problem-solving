class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> output;
        
        for(int i = 1;i <= n;i++){
            string s = "";
            if((i % 3) && (i % 5))
                s = to_string(i);
            else{
                if(!(i % 3))
                    s += "Fizz";
                if(!(i % 5))
                    s += "Buzz";
            }
            output.push_back(s);
        }
        return output;
    }
};
