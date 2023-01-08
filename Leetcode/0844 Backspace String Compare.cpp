class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1;
        int j = T.size() - 1;
        
        int i_back = 0,j_back = 0;
        
        while(i >= 0 or j >= 0){
            
            while(i >= 0){
                if(S[i] == '#')
                    ++i_back,--i;
                else if(i_back > 0)
                    --i_back,--i;
                else
                    break;
            }
            
            while(j >= 0){
                if(T[j] == '#')
                    ++j_back,--j;
                else if(j_back > 0)
                    --j_back,--j;
                else
                    break;
            }
            
            if(i < 0 and j < 0)
                return true;
            if(i < 0 or j < 0 or S[i] != T[j])
                return false;
            
            --i;--j;
        }
        
        return true;
    }
};