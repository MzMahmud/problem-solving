class Solution {
public:
    int numberOfSteps (int num) {
        bool foundLeadingOne = false;
        int ones = 0,zeros = 0; 
        for(int i = 31;i >= 0;i--){
            if( num & (1<<i) ){//bit is one
                foundLeadingOne = true;
                ones++;
            }
            else if(foundLeadingOne)
                zeros++;
        }
        
        // every zeros takes one step to remove
        // every ones takes two step to remove except the last one
        return (ones << 1) + zeros - 1;
    }
};

    
