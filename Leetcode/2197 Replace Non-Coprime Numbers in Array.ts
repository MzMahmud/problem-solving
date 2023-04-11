function replaceNonCoprimes(nums: number[]): number[] {
    const stack: number[] = [];
    for (const num of nums) {
        let n = num;
        while (true) {
            const g = gcd(stack.length === 0? 1 :  stack[stack.length-1], n);
            if (g === 1){
                break;
            }
            n *= (stack.pop() as number) / g;
        }    
        stack.push(n);
    }
    return stack;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
