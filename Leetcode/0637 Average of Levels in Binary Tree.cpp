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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<Pair> q;
        if(root)
            q.push(Pair(root));
        
        vector<double> avg;
        int level = 0;
        double sum = .0;
        int nums = 0;
        
        while(!q.empty()){
            Pair u = q.front();
            q.pop();
            
            if(u.p->left)
                q.push(Pair(u.p->left,u.level + 1));
            if(u.p->right)
                q.push(Pair(u.p->right,u.level + 1));
            
            if(level != u.level){
                avg.push_back(sum/nums);
                
                level = u.level;
                sum  = .0;
                nums =  0;
            }
            sum += u.p->val;
            nums++;
        }
        if(nums)
            avg.push_back(sum/nums);
        return avg;
    }
};


