class WordDictionary {
    private final Node root;

    public WordDictionary() {
        root = new Node();
        root.isWordEnd = true;
    }

    public void addWord(String word) {
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
        return search(0, root, word);
    }

    private boolean search(int index, Node node, String word) {
        if (node == null) {
            return false;
        }
        if (index == word.length()) {
            return node.isWordEnd;
        }
        char ch = word.charAt(index);
        if (ch != '.') {
            return search(index + 1, node.children[ch - 'a'], word);
        }
        for (int charIndex = 0; charIndex < ALPHABET_SIZE; ++charIndex) {
            if (search(index + 1, node.children[charIndex], word)) {
                return true;
            }
        }
        return false;
    }

    private static final int ALPHABET_SIZE = 26;

    private static class Node {
        boolean isWordEnd;
        Node[] children = new Node[ALPHABET_SIZE];
    }
}