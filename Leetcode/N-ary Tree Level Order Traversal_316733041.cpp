/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        vector<int> level;
        
        queue<pair<Node*,int>> q;
        
        if(root)
            q.push(make_pair(root,0));
        
        int cur_level = -1;
        
        while(!q.empty()){
            Node *u     = q.front().first;
            int u_level = q.front().second;
            q.pop();
            
            
            if(u_level != cur_level){
                if(level.size() > 0){
                    levels.push_back(level);
                    level.clear();
                    cur_level = u_level;
                }
            }
            
            level.push_back(u->val);
            
            for(int i = 0;i < u->children.size();i++){
                Node *v = u->children[i];
                q.push(make_pair(v,u_level + 1));
            }
        }
        
        if(level.size() > 0){
            levels.push_back(level);
            level.clear();
        }
        return levels;
    }
};
