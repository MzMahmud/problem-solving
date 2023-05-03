function pivotArray(nums: number[], pivot: number): number[] {
    let low = 0, equal = 0;
    for (const n of nums) {
        if (n < pivot) low++;
        else if (n === pivot) equal++; 
    }
    let high = equal + low;
    equal = low, low  = 0;
    const result = new Array<number>(nums.length);
    for (const n of nums) {
        if (n < pivot) result[low++] = n;
        else if (n === pivot) result[equal++] = n;
        else result[high++] = n;
    }
    return result;
}
