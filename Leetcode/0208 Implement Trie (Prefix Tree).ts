class TrieNode {
    children: Map<string, TrieNode>
    isEndOfWord: boolean

    constructor() {
        this.children = new Map();
        this.isEndOfWord = false;
    }
}

class Trie {
    root: TrieNode

    constructor() {
        this.root = new TrieNode();
    }

    insert(word: string): void {
        let curr = this.root;
        for (const char of word) {
            if (!curr.children.has(char)) {
                curr.children.set(char, new TrieNode());
            }
            curr = curr.children.get(char) as TrieNode;
        }
        curr.isEndOfWord = true;
    }

    search(word: string): boolean {
        let curr: TrieNode | undefined = this.root;
        for (let i = 0; i < word.length && curr != null; i++) {
            curr = curr.children.get(word[i]);
        }
        return curr != null && curr.isEndOfWord;
    }

    startsWith(prefix: string): boolean {
        let curr: TrieNode | undefined = this.root;
        for (let i = 0; i < prefix.length && curr != null; i++) {
            curr = curr.children.get(prefix[i]);
        }
        return curr != null;
    }
}
