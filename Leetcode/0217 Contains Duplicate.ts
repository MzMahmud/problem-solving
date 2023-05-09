function containsDuplicate(nums: number[]): boolean {
    const present = new Set<number>();
    for (let n of nums) {
        if (present.has(n)) {
            return true;
        }
        present.add(n);
    }
    return false;
}
