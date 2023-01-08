class MinStack {
    stack<pair<int,int>> m_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(m_stack.empty())
            m_stack.push(make_pair(x,x));
        else
            m_stack.push(make_pair(x,min(x,m_stack.top().second)));
    }
    
    void pop() {
        if(!m_stack.empty())
            m_stack.pop();
    }
    
    int top() {
        return m_stack.top().first;
    }
    
    int getMin() {
        return m_stack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */