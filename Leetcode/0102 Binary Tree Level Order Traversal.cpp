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

        Pair(TreeNode *_p,int _level = 0) : p(_p),level(_level) {}
};

class Solution{
public:
    
    vector<vector<int>> levelOrder(TreeNode *root){
            queue<Pair> q;

            if(root)
                q.push(Pair(root));

            vector<vector<int>> all;
            vector<int> levelVect;
            int currLevel = 0;

            while(!q.empty()){
                    Pair u = q.front();q.pop();
                
                    if(u.p->left)
                        q.push(Pair(u.p->left  ,u.level + 1));
                    if(u.p->right)
                        q.push(Pair(u.p->right,u.level + 1));

                    if(u.level != currLevel){
                            all.push_back(levelVect);
                            currLevel = u.level;
                            levelVect.clear();
                    }

                    levelVect.push_back(u.p->val);
            }

            if(levelVect.size())
                all.push_back(levelVect);

            return all;
    }
};
