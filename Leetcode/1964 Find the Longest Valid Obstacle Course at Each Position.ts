function longestObstacleCourseAtEachPosition(obstacles: number[]): number[] {
    const maxHeightByLen = [-1];
    const lengths = new Array<number>(obstacles.length);
    for (let i = 0; i < obstacles.length; i++) {
        const length = getFirstGreaterIndex(maxHeightByLen, obstacles[i]);
        if (length === maxHeightByLen.length) {
            maxHeightByLen.push(obstacles[i]);
        } else {
            maxHeightByLen[length] = Math.min(maxHeightByLen[length], obstacles[i]);
        }
        lengths[i] = length;
    }
    return lengths;
}

function getFirstGreaterIndex(heights: number[], height: number): number {
    let lo = 0, hi = heights.length - 1;
    while (lo <= hi) {
        const mid = lo + Math.floor((hi - lo) / 2);
        if (heights[mid] > height) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    } 
    return lo;
}
