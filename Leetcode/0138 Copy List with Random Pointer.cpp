/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
    unordered_map<Node*,Node*> old_new;
public:
    Node* copyRandomList(Node* head) {
        Node *curr = head;
        while(curr){
            Node *newNode  = new Node(curr->val);
            old_new[curr]  = newNode;
            curr = curr->next;
        }
        
        curr = head;
        while(curr){
            old_new[curr]->next   = old_new[curr->next];
            old_new[curr]->random = old_new[curr->random];
            
            curr = curr->next;
        }
        
        return old_new[head];
    }
};
