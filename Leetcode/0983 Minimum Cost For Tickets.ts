const durations = [1, 7, 30];

function mincostTickets(days: number[], costs: number[]): number {
    const cache: number[] = new Array(days.length).fill(null);

    function minCost(dayIndex: number) {
        if (dayIndex >= days.length) {
            return 0;
        }
        if (cache[dayIndex] != null) {
            return cache[dayIndex];
        }
        let cost = Infinity;
        for (let costIndex = 0; costIndex < costs.length; costIndex++) {
            let j = dayIndex;
            while (j < days.length && days[j] < days[dayIndex] + durations[costIndex]) {
                j++
            }
            cost = Math.min(cost, costs[costIndex] + minCost(j));
        }
        return cache[dayIndex] = cost;
    }

    return minCost(0);
}
