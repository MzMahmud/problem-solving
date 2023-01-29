class Trie {
    private final Node root;

    public Trie() {
        root = new Node();
        root.isWordEnd = true;
    }

    public void insert(String word) {
        var currNode = root;
        for (int i = 0; i < word.length(); ++i) {
            int charIndex = word.charAt(i) - 'a';
            if (currNode.children[charIndex] == null) {
                currNode.children[charIndex] = new Node();
            }
            currNode = currNode.children[charIndex];
        }
        currNode.isWordEnd = true;
    }

    public boolean search(String word) {
        var currNode = root;
        for (int i = 0; currNode != null && i < word.length(); ++i) {
            int charIndex = word.charAt(i) - 'a';
            currNode = currNode.children[charIndex];
        }
        return currNode != null && currNode.isWordEnd;
    }

    public boolean startsWith(String prefix) {
        var currNode = root;
        for (int i = 0; currNode != null && i < prefix.length(); ++i) {
            int charIndex = prefix.charAt(i) - 'a';
            currNode = currNode.children[charIndex];
        }
        return currNode != null;
    }

    private static final int ALPHABET_SIZE = 26;

    private static class Node {
        boolean isWordEnd;
        Node[] children = new Node[ALPHABET_SIZE];
    }
}