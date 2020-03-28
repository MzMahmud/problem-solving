class Solution {
public:
    int numberOfSteps (int num) {
        bool foundLeading1 = false;
        int ones = 0,zeros = 0; 
        for(int i = 31;i >= 0;i--){
            if( num & (1<<i) ){//bit is one
                foundLeading1 = true;
                ones++;
            }else if(foundLeading1){
                zeros++;
            }
        }
        return (ones << 1) + zeros - 1;
    }
};

    
