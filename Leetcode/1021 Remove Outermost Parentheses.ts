function removeOuterParentheses(s: string): string {
    const parts: string[] = [];
    let count = 0, start = -1;
    for (let i = 0;i < s.length; i++) {
        if (s[i] === '(') {
            if (count === 0) {
                start = i + 1;
            }
            count++;
        } else {
            count--;
            if (count === 0) {
                parts.push(s.substring(start, i));
            }
        }
    }
    return parts.join("");
}
