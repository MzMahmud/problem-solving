/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct NodeLevel{
    TreeNode *node;
    int level;
    NodeLevel(TreeNode *n,int l) : node(n),level(l){}
};
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<NodeLevel> q;
        
        if(root) q.emplace(root,1);
        
        int curr_level = q.front().level,max_level;
        int level_sum  = 0,max_sum = INT_MIN;
        
        while(!q.empty()){
            auto p = q.front();q.pop();
            
            int level = p.level;
            TreeNode *u = p.node;
            
            if(level != curr_level){
                if(level_sum > max_sum){
                    max_sum   = level_sum;
                    max_level = curr_level;
                }
                level_sum  = 0;
                curr_level = level; 
            }
            
            level_sum += u->val;
            
            if(u->left)  q.emplace(u->left ,level + 1);            
            if(u->right) q.emplace(u->right,level + 1);  
        }
        
        return max_level;
    }
};