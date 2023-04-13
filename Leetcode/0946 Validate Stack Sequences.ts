function validateStackSequences(pushed: number[], popped: number[]): boolean {
    const pushing: number[] = [];
    let poppedTop = 0;
    for (const val of pushed) {
        pushing.push(val);
        while (
            pushing.length !== 0 
            && poppedTop < popped.length 
            && pushing[pushing.length - 1] === popped[poppedTop]
        ) {
            pushing.pop();
            poppedTop++;
        }
    }
    return poppedTop == popped.length && pushing.length === 0;
}
