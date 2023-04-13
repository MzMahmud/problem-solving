function maxDepth(s: string): number {
    let depth = 0, maximumDepth = 0;
    for (const c of s) {
        if (c === '(') {
            depth++;
            if (depth > maximumDepth) {
                maximumDepth = depth;    
            }
        } else if (c === ')') {
            depth--;
        }
    }    
    return maximumDepth;
}
