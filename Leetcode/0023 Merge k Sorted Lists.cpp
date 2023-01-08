class Cmp{
    public:
    bool operator()(ListNode *one, ListNode *other){
        return one->val > other->val;
    }
};

class Solution {

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *,
                       vector<ListNode *>,
                       Cmp > nodes;

        for (auto list : lists)
            if (list)
                nodes.push(list);

        ListNode *marged = new ListNode(0);
        ListNode *prev   = marged;

        while (!nodes.empty()) {
            ListNode *newNode = new ListNode(nodes.top()->val);
            prev->next        = newNode;
            prev              = newNode;

            if (nodes.top()->next)
                nodes.push(nodes.top()->next);
            nodes.pop();
        }
        return marged->next;
    }
};
