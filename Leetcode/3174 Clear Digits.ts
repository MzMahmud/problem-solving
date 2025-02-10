function clearDigits(s: string): string {
    const stack: string[] = [];
    for (const ch of s) {
        if (isDigit(ch)) {
            stack.length > 0 && stack.pop();
        } else {
            stack.push(ch);
        }
    }
    return stack.join("");
}

function isDigit(s: string) {
    return /^[0-9]$/.test(s);
}
