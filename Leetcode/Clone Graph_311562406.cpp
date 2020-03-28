/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
   unordered_map<Node*,Node*> copied;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        
        if(copied[node])
            return copied[node];
        
        Node* newNode = new Node(node->val);
        copied[node] = newNode;//visit the node
        
        for(int i = 0;i < node->neighbors.size();i++)
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
            
        return newNode;
    }
};
