// O(n) Time | O(n) Space
const longestConsecutive = function (numbers) {
    const uniqueNumbers = new Set(numbers);
    let maxRangeLength = 0;
    for (const number of numbers) {
        let rangeStart = number - 1;
        while (uniqueNumbers.has(rangeStart)) {
            --rangeStart;
            uniqueNumbers.delete(number);
        }
        let rangeEnd = number + 1;
        while (uniqueNumbers.has(rangeEnd)) {
            ++rangeEnd;
            uniqueNumbers.delete(number);
        }
        const currentRangeLength = rangeEnd - rangeStart - 1;
        maxRangeLength = Math.max(maxRangeLength, currentRangeLength);
    }
    return maxRangeLength;
};

