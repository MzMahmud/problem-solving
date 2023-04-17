function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
    let maxVal = candies[0];
    for (const val of candies) {
        maxVal = Math.max(maxVal, val);
    }
    return candies.map(val => val + extraCandies >= maxVal);
}
