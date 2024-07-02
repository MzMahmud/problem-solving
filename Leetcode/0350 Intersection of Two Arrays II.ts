function intersect(a: number[], b: number[]): number[] {
    const count: Record<number, number> = {};
    for (const n of a) {
        count[n] = (count[n] ?? 0) + 1; 
    }
    const intersection: number[] = [];
    for (const n of b) {
        if (count[n]) {
            intersection.push(n);
            count[n]--;
        }
    }
    return intersection;
}
