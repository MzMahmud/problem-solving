function makeFancyString(s: string): string {
    let fancyStr = "", sameChars = "";
    for (const ch of s) {
        if (ch === sameChars) {
            sameChars += ch;
        } else {
            sameChars = ch;
        }
        if (sameChars.length < 3) {
            fancyStr += ch;
        }
    }
    return fancyStr;
}
