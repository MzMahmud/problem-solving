class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // go from backward
        int i_1 = m - 1;
        int i_2 = n - 1;
        int i   = m + n -1;
        
        while(i_1 >= 0 && i_2 >= 0){
            if(nums1[i_1] > nums2[i_2])
                nums1[i--] = nums1[i_1--]; 
            else
                nums1[i--] = nums2[i_2--];
        }
        
        while(i_2 >= 0)
            nums1[i--] = nums2[i_2--];
        while(i_1 >= 0)
            nums1[i--] = nums1[i_1--];
    }
};
