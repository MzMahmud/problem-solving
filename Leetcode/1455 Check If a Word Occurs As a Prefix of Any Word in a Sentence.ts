function isPrefixOfWord(sentence: string, searchWord: string): number {
    let index = 1;
    let word = "";
    for (let i = 0;i <= sentence.length; i++) {
        if (i == sentence.length || sentence[i] == " ") {
            if (word.startsWith(searchWord)) return index;
            word = "";
            ++index;
        } else {
            word += sentence[i];
        }   
    }
    return -1;
}
