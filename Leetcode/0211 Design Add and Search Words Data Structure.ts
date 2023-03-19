type WordDictNode = {
    isEndOfWord: boolean;
    children: Map<string, WordDictNode>;
}

class WordDictionary {
    root: WordDictNode;

    constructor() {
        this.root = {
            isEndOfWord: false,
            children: new Map()
        }
    }

    addWord(word: string): void {
        let curr = this.root;
        for(const char of word) {
            if(!curr.children.has(char)) {
                curr.children.set(
                    char, {
                    isEndOfWord: false,
                    children: new Map()
                });
            }
            curr = curr.children.get(char);
        }
        curr.isEndOfWord = true;
    }

    searchFromIndex(word: string, index: number, root: WordDictNode): boolean {
        if(index == word.length) {
            return root.isEndOfWord;
        }
        const char = word[index];
        if(char === '.') {
            for(const child of root.children.values()) {
                if(this.searchFromIndex(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        }
        const child = root.children.get(char);
        return child != null && this.searchFromIndex(word, index + 1, child);
    }

    search(word: string): boolean {
        return this.searchFromIndex(word, 0, this.root);
    }
}
