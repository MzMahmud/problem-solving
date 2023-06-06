function canMakeArithmeticProgression(arr: number[]): boolean {
    arr.sort((a, b) => a - b);
    const diff = arr[1] - arr[0];
    for (let i = 2; i < arr.length; i++) {
        const diffI = arr[i] - arr[i - 1];
        if (diff !== diffI) {
            return false;
        }
    }
    return true;
}
