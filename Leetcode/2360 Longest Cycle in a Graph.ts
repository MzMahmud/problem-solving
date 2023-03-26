function longestCycle(edges: number[]): number {
    let longestCycleLen = -1;
    let time = 1;
    const visitTime: number[] = new Array(edges.length).fill(0);
    for(let node = 1; node < edges.length; node++) {
        if (visitTime[node] != 0) {
            continue;
        }
        const startTime = time;
        while(node != -1 && visitTime[node] == 0) {
            visitTime[node] = time;
            time++;
            node = edges[node];
        }
        if(node != -1 && visitTime[node] >= startTime) {
            const currCycleLen = time - visitTime[node];
            longestCycleLen = Math.max(longestCycleLen, currCycleLen);
        }
    }
    return longestCycleLen;
}
