/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Pair{
    TreeNode *node;
    int val;
    
    Pair(TreeNode *n,int v){
        node = n;
        val  = v;
    }
};
class Solution {
    vector<Pair> nodes;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        
        inOrder(root);
        
        for(int i = nodes.size() - 2;i >= 0;i--){
            nodes[i].val       += nodes[i + 1].val;
            nodes[i].node->val  = nodes[i].val;
        }
        
        return root;
    }
    
    void inOrder(TreeNode *root){
        if(!root)
            return;
        inOrder(root->left);
        nodes.push_back(Pair(root,root->val));
        inOrder(root->right);
    }
};
