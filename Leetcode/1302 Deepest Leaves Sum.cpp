/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct LevelVal{
    int level,val;
    LevelVal(int l,int v) : level(l),val(v){}
    
    bool operator<(const LevelVal &other) const {
        return level < other.level;
    }
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(root)
            q.push(make_pair(root,0));
        
        int level_sum = 0;
        int cur_level = 0;
        while(!q.empty()){
            auto u = q.front();q.pop();
            
            if(u.second != cur_level){
                cur_level = u.second;
                level_sum = 0;
            }
            
            level_sum += u.first->val;
            
            if(u.first->left)
                q.push(make_pair(u.first->left,u.second + 1));
            
            if(u.first->right)
                q.push(make_pair(u.first->right,u.second + 1));
        }
        return level_sum;
    }
};