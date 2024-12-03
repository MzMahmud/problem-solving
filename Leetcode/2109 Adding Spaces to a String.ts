function addSpaces(s: string, spaces: number[]): string {
    const chars = new Array<string>(s.length + spaces.length);
    for (let i = 0, j = 0, k = 0; i < s.length; i++) {
        if (j < spaces.length && i == spaces[j]) {
            j++;
            chars[k++] = " ";
        }
        chars[k++] = s[i];
    }
    return chars.join("");
}
