// O(n) Time | O(n) Space
// solution explanation: https://youtu.be/P6RZZMu_maU
const longestConsecutive = function (numbers) {
    const uniqueNumbers = new Set(numbers);
    let maxRangeLength = 0;
    for (const number of numbers) {
        if (uniqueNumbers.has(number - 1)) {
            continue;
        }
        let upperLimit = number + 1;
        while (uniqueNumbers.has(upperLimit)) {
            ++upperLimit;
        }
        let currentRangeLength = upperLimit - number;
        maxRangeLength = Math.max(maxRangeLength, currentRangeLength);
    }
    return maxRangeLength;
}
