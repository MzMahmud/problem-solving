class LRUCache {
    private final int capacity;
    private final Map<Integer, Node> nodeByKey;
    private Node head, tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.nodeByKey = new HashMap<>();
        this.head = null;
        this.tail = null;
    }

    public int get(int key) {
        var node = nodeByKey.get(key);
        if (node == null) {
            return -1;
        }
        if (node == head) {
            return node.value;
        }
        node.prev.next = node.next;
        if (node.next == null) {
            tail = node.prev;
        } else {
            node.next.prev = node.prev;
        }
        node.next = head;
        head.prev = node;
        head = node;
        return node.value;
    }

    private void removeTail() {
        if(tail == null) {
            return;
        }
        if(tail.prev == null) {
            head = null;
        } else {
            tail.prev.next = null;
        }
        nodeByKey.remove(tail.key);
        tail = tail.prev;
    }

    public void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        var node = nodeByKey.get(key);
        if (node != null) {
            node.value = value;
            get(key);
            return;
        }
        if (nodeByKey.size() == capacity) {
            removeTail();
        }
        var newNode = new Node(key, value, null, head);
        if (head == null) {
            tail = newNode;
        } else {
            head.prev = newNode;
        }
        head = newNode;
        nodeByKey.put(key, head);
    }

    static class Node {
        int key, value;
        Node prev, next;

        public Node(int key, int value, Node prev, Node next) {
            this.key = key;
            this.value = value;
            this.prev = prev;
            this.next = next;
        }
    }
}