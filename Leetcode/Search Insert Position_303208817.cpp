class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = binarySearch(target,nums);
        
        return (index >= 0)? index :(-1*(index+1));
    }
    int binarySearch(int x,vector<int>& a){
        int pos,low,up,mid;
        low = 0,up  = (int) a.size() - 1;
        while(low <= up){
            mid = (low+up)/2;
            if(a[mid] == x) return mid;//if found returns the found index
            else if(x > a[mid]) low = mid + 1;
            else if(x < a[mid]) up  = mid - 1;
        }
        //if not found returns the -1*(correct sitting position + 1)
        //-ve will denote not found and +1 allows to distinguish betwn found at 0 and not found at 0
        ///to get correct sitting position -1*(returned value + 1)

        if(x > a[mid]) mid++;//if the key is larger then it would sit next else the position in mid
        return -1*(mid+1);
    }
};
