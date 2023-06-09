function nextGreatestLetter(letters: string[], target: string): string {
    let lo = 0, hi = letters.length - 1, greaterIndex = 0;
    while (lo <= hi) {
        const mid = lo + Math.floor((hi - lo) / 2);
        if (letters[mid] > target) {
            hi = mid - 1;
            greaterIndex = mid;
        } else {
            lo = mid + 1;
        }
    }
    return letters[greaterIndex];
}
