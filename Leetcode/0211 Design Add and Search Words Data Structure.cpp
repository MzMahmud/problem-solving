// implemented trie

class WordDictionary {
    struct Node {
        unordered_map<char, Node*> children;
        bool is_end_of_the_word;
        
        Node() {
            is_end_of_the_word = false;
        }
        
        bool contains_child(char child_char) {
            return children.find(child_char) != children.end();
        }
    };
    Node root;

    bool search(Node *node, const string &word, int start_index) {
        const char &c = word[start_index]; 
        if(start_index == word.size()) {
            return node->is_end_of_the_word;
        }
        bool exists = false;
        if(c == '.') {
            for(const auto &[key, value] : node->children) {
                exists |= search(value, word, start_index + 1);
            }
        } else if(node->contains_child(c)){
            exists |= search(node->children[c], word, start_index + 1);
        }
        return exists;
    }
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node *curr_node = &root;
        int n = word.size();
        for(int i = 0;i < n; ++i) {
            const char &c = word[i];
            if(!curr_node->contains_child(c)) {
                curr_node->children[c] = new Node;
            }
            curr_node = curr_node->children[c];                
            if(i == (n - 1)) {
                curr_node->is_end_of_the_word = true;
            }
        }
    }
    
    bool search(string word) {
        return search(&root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
