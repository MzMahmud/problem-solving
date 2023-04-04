const ALPHABET_SIZE = 26;

function partitionString(s: string): number {
    const lastIndex: number[] = new Array(ALPHABET_SIZE).fill(-1);
    let startIndex = -1, nPartitions = 0;
    for(let i = 0; i < s.length; i++) {
        const charIndex = getCharIndex(s[i]);
        if(lastIndex[charIndex] >= startIndex) {
            nPartitions++;
            startIndex = i;
        }
        lastIndex[charIndex] = i;
    }
    return nPartitions;
}

const SMALL_A_CHAR_CODE = 'a'.charCodeAt(0);

function getCharIndex(char: string): number {
    return char.charCodeAt(0) - SMALL_A_CHAR_CODE;
}
