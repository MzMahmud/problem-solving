function intersect(a: number[], b: number[]): number[] {
    const bCounter = counter(b);
    const intersec = [];
    for (const ai of a) {
        const bCount = bCounter.get(ai) ?? 0;
        if (bCount !== 0) {
            intersec.push(ai);
            bCounter.set(ai, bCount - 1);
        }
    }
    return intersec;
}

function counter(a: number[]) {
    const counts = new Map<number, number>();
    for (const ai of a) {
        const count = (counts.get(ai) ?? 0) + 1;
        counts.set(ai, count);
    }
    return counts;
}
