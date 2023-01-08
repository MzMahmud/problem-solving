/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1,list2;
        
        inOrder(root1,list1);        
        inOrder(root2,list2);
        
        int i = 0,j = 0,k = 0;
        int n = list1.size();
        int m = list2.size();
        vector<int> list(n + m);
        while(i < n && j < m){
            if(list1[i] < list2[j])
                list[k++] = list1[i++];
            else
                list[k++] = list2[j++];
        }
        
        while(i < n)
            list[k++] = list1[i++];
        while(j < m)
            list[k++] = list2[j++];
        
        return list;
    }
    
    void inOrder(TreeNode *root,vector<int> &list){
        if(!root) return;
        
        inOrder(root->left,list);
        
        list.push_back(root->val);
        
        inOrder(root->right,list);
    }
};
