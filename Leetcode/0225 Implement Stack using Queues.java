class MyStack {
    private int topValue;
    private final Queue<Integer> queue;

    public MyStack() {
        queue = new LinkedList<>();
    }
    
    public void push(int x) {
        topValue = x;
        queue.add(topValue);
    }
    
    public int pop() {
        int size = queue.size();
        for(int i = 1; i <= size; ++i) {
            int front = queue.poll();
            if (i == size) {
                return front;
            }
            queue.add(front);
            topValue = front;
        }
        return 0;
    }
    
    public int top() {
        return topValue;
    }
    
    public boolean empty() {
        return queue.isEmpty();
    }
}
