function separateDigits(nums: number[]): number[] {
    const digits: number[] = [];
    for (const n of nums) {
        for (const d of `${n}`) {
            digits.push(parseInt(d));
        }
    }
    return digits;
}
