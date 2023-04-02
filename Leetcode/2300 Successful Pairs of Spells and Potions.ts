// sorting + binary search solution
// O(m log m + n log m)
function successfulPairs(
    spells: number[], potions: number[], success: number
) {
    // O(m log m)
    potions.sort((a, b) => a - b);
    // O(log m)
    const getNumberOfSuccess = (spell: number) => {
        const factor = Math.ceil(success / spell);
        const lowerBound = findLowerBound(potions, factor);
        return potions.length - lowerBound;
    }
    // n times and ever time is O(log m)
    return spells.map(getNumberOfSuccess);
    // final O(m log m + n log m)
}


function findLowerBound(numbers: number[], target: number) {
    let lo = 0, hi = numbers.length - 1;
    while (lo <= hi) {
        const mid = lo + Math.floor((hi - lo) / 2);
        if (numbers[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}
