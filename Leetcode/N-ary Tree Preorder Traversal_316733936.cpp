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
    vector<int> preorder(Node* root) {
        vector<int> pre;
        preorder(root,pre);
        return pre;
    }
    
    void preorder(Node* root,vector<int> &pre){
        if(!root)
            return;
        
        pre.push_back(root->val);
        for(int i = 0;i < root->children.size();i++)
            preorder(root->children[i],pre);
    }
};
