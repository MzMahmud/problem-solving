/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node{
    TreeNode *node;
    int level;
    Node(TreeNode *n,int l) : node(n),level(l) {}
};

struct MaxVal{
    int val;
    bool valid;
    MaxVal(int v = 0,bool va = 0) : val(v),valid(va){} 
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<Node> q;
        if(root) q.emplace(root,0);
        int curr_level = -1;
        
        MaxVal largest;
        
        vector<int> row_largests;
        
        while(!q.empty()){
            Node u = q.front();q.pop();
            
            if(u.level != curr_level){
                
                if(largest.valid)
                    row_largests.push_back(largest.val);
                
                largest.valid = false;
                curr_level    = u.level;
            }
            
            if(!largest.valid or u.node->val > largest.val){
                largest.val   = u.node->val;
                largest.valid = true;
            }
            
            if(u.node->left)  q.emplace(u.node->left ,u.level + 1);
            if(u.node->right) q.emplace(u.node->right,u.level + 1);
        }
        
        if(largest.valid)
            row_largests.push_back(largest.val);
        
        return row_largests;
    }
};