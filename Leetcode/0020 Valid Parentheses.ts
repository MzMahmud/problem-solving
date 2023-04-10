const rightToLeftMap = {
    ')': '(', 
    '}': '{',
    ']': '[',
};

function isValid(s: string): boolean {
    const stack = [];
    for(const char of s) {
        const isLeftParentheses = ['(', '{', '['].includes(char);
        if(isLeftParentheses) {
            stack.push(char);
            continue;
        }
        const stackTop = stack[stack.length - 1];
        if(stackTop == null || stackTop !== rightToLeftMap[char]) {
            return false;
        }
        stack.pop();
    }
    return stack.length === 0;
}
