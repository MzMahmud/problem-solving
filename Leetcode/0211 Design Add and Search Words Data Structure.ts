class WordDictNode {
    isEndOfWord: boolean = false;
    children: Map<string, WordDictNode> = new Map();
}

class WordDictionary {
    root: WordDictNode = new WordDictNode();

    addWord(word: string): void {
        let curr = this.root;
        for(const char of word) {
            if(!curr.children.has(char)) {
                curr.children.set(char, new WordDictNode());
            }
            curr = curr.children.get(char);
        }
        curr.isEndOfWord = true;
    }

    search(word: string, index: number = 0, root: WordDictNode = this.root): boolean {
        if(index == word.length) {
            return root.isEndOfWord;
        }

        const char = word[index];
        if(char !== '.') {
            const child = root.children.get(char);
            return child != null && this.search(word, index + 1, child);
        }

        for(const child of root.children.values()) {
            if(this.search(word, index + 1, child)) {
                return true;
            }
        }
        return false;
    }
}
