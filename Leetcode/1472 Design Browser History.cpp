class BrowserHistory {
    struct Node {
        string url;
        Node *prev, *next;
        
        Node(const string &url, Node *prev, Node *next) 
            : url(url), prev(prev), next(next) {}
        
        Node(const string &url) 
            : url(url), prev(nullptr), next(nullptr) {}
    };
    
    void delete_list(Node *node) {
        while(node != nullptr) {
            Node *to_delete = node;
            node = node->next;
            delete to_delete;
        }
    }
    
    Node *current;
public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        delete_list(current->next);
        current = current->next = new Node(url, current, nullptr);
    }
    
    string back(int steps) {
        int n_steps = 0;
        while(current->prev != nullptr and n_steps < steps) {
            current = current->prev;
            ++n_steps;
        }
        return current->url;
    }
    
    string forward(int steps) {
        int n_steps = 0;
        while(current->next != nullptr and n_steps < steps) {
            current = current->next;     
            ++n_steps;
        }
        return current->url;
    }
};
