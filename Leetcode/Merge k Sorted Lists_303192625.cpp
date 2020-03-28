class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.empty())
            return nullptr;
            
        map<int, int> m;    //  key is a element from list, value is the frequency of occurrence of the element  
        
        for(auto i : lists) {
            while( i != nullptr )
            {
                auto ret = m.insert(std::pair<int,int>(i->val, 1));
                
                if(ret.second == false) // false if element already exists
                    m[i->val]++;
                
                i = i->next;
            }
        }
        
        if(m.empty())
            return nullptr;
        
        ListNode* head = new ListNode(0);
        ListNode * current = head;
        head->next = current;
        
        for( auto i : m ) {
        
            while(i.second > 0) {
                current->next = new ListNode(i.first);
                i.second--;
                current = current->next;
            }
        }
        
        return head->next;
    }
};
