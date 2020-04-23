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

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<Node> q;
        if(root) q.emplace(root,0);
        int curr_level = -1,bottom_left;
        
        while(!q.empty()){
            Node u = q.front();q.pop();
            
            if(u.level != curr_level){
                bottom_left = u.node->val;
                curr_level  = u.level;
            }
            
            if(u.node->left)  q.emplace(u.node->left ,u.level + 1);
            if(u.node->right) q.emplace(u.node->right,u.level + 1);
        }
        return bottom_left;
    }
};