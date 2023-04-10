const rightToLeftMap = { ')': '(', '}': '{', ']': '[' };

function isValid(s: string): boolean {
    const stack = [];
    for(const char of s) {
        if(['(', '{', '['].includes(char)) {
            stack.push(char);
        } else if(stack.length === 0 || stack.pop() !== rightToLeftMap[char]) {
            return false;
        }
    }
    return stack.length === 0;
}
