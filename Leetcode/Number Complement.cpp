class Solution {
public:
    int findComplement(int num) {
        bool found_msb = false;
        for(int i = 31;i >= 0;i--){
            if(num & (1 << i))
               found_msb = true;
        
            if(found_msb)
                num ^= (1 << i);
        }
        return num;
    }
};