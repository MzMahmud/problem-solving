function checkIfExist(arr: number[]): boolean {
    const seen = new Set<number>();
    for (const num of arr) {
        if (seen.has(num << 1)) return true;
        if ((num & 1) == 0 && seen.has(num >> 1)) return true;
        seen.add(num);
    }
    return false;
}
