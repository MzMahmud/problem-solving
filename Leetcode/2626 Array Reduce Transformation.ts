type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    let value = init;
    for(const num of nums) {
        value = fn(value, num);
    }
    return value;
}
