const UN_VISITED = 0, VISITING = 1, VISITED = 2;
type VisitStatus = 0 | 1 | 2;
const CONTAINS_CYCLE = -1;
const N_COLORS = 26;

function largestPathValue(colors: string, edges: number[][]): number {
    const n = colors.length;
    const adjList: number[][] = new Array();
    const frequentColorFreq: number[][] = new Array(n);
    for(let i = 0;i < n; i++) {
        adjList[i] = [];
        frequentColorFreq[i] = new Array(N_COLORS).fill(0);
    }
    for(const [src, dst] of edges) {
        adjList[src].push(dst);
    }
    const visitStatus: VisitStatus[] = new Array(n).fill(UN_VISITED);
    let mostFrequentFreq = -1;
    for(let node = 0; node < n; node++) {
        if(visitStatus[node] !== UN_VISITED) {
            continue;
        }
        const freqFromNode = dfs(node, adjList, colors, visitStatus, frequentColorFreq);
        if(freqFromNode === CONTAINS_CYCLE) {
            return -1;
        }
        mostFrequentFreq = Math.max(mostFrequentFreq, freqFromNode);
    }
    return mostFrequentFreq;
}

function dfs(
    start: number, 
    adjList: number[][],
    colors: string, 
    visitStatus: VisitStatus[], 
    frequentColorFreq: number[][]
): number {
    if (visitStatus[start] === VISITING) {
        return CONTAINS_CYCLE;
    }
    if (visitStatus[start] === VISITED) {
        return Math.max(...frequentColorFreq[start]);
    }
    visitStatus[start] = VISITING;
    const startColor = colors.charCodeAt(start) - 'a'.charCodeAt(0);
    for(const neighbour of adjList[start]) {
        const neighbourFreq = dfs(neighbour, adjList, colors, visitStatus, frequentColorFreq);
        if(neighbourFreq === CONTAINS_CYCLE) {
            return CONTAINS_CYCLE;
        }
        for(let color = 0; color < N_COLORS; color++) {
            frequentColorFreq[start][color] = Math.max(
                frequentColorFreq[start][color],
                frequentColorFreq[neighbour][color]
            );
        }
    }
    frequentColorFreq[start][startColor]++;
    visitStatus[start] = VISITED;
    return Math.max(...frequentColorFreq[start]);
}
