class MyQueue {
    private final Stack<Integer> pushStack;
    private final Stack<Integer> popStack;

    public MyQueue() {
        pushStack = new Stack<>();
        popStack = new Stack<>();
    }
    
    public void push(int x) {
        pushStack.add(x);
    }
    
    public int pop() {
        populatePopStack();
        return popStack.pop();
    }
    
    public int peek() {
        populatePopStack();
        return popStack.peek(); 
    }

    private void populatePopStack() {
        if(!popStack.isEmpty()) {
            return;
        }
        while(!pushStack.isEmpty()) {
            popStack.add(pushStack.pop());
        }
    }
    
    public boolean empty() {
        return pushStack.isEmpty() && popStack.isEmpty();
    }
}
