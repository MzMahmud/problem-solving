function findDifference(a: number[], b: number[]): number[][] {
    return [setDifference(a, b), setDifference(b, a)];
}

function setDifference(a: number[], b: number[]): number[] {
    const bSet = new Set<number>(b);
    const aMinusB = new Set<number>();
    for (const ai of a) {
        if (!bSet.has(ai)) {
            aMinusB.add(ai);
        }
    }
    return [...aMinusB];
}
