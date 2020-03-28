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
    TreeNode *p;
    int level;
    Pair(TreeNode *_p,int _level = 0)
        : p(_p),level(_level){}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<Pair> q;
        if(root)
            q.push(Pair(root));
        
        vector<vector<int>> all;
        vector<int> row;
        int level = 0;
        
        while(!q.empty()){
            Pair u = q.front();
            q.pop();
            
            if(u.p->left)
                q.push(Pair(u.p->left,u.level + 1));
            if(u.p->right)
                q.push(Pair(u.p->right,u.level + 1));
            
            if(level != u.level){
                level = u.level;
                all.push_back(row);
                row.clear();
            }
            row.push_back(u.p->val);
        }
        if(row.size())
            all.push_back(row);
        
        int i = 0,j = (int)all.size() - 1;
        while(i <= j)
            swap(all[i++],all[j--]);
        
        return all;
        
        
    }
};


