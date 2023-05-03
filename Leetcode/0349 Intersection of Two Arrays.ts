function intersection(a: number[], b: number[]): number[] {
    const aSet = new Set<number>(a);
    const bSet = new Set<number>(b);
    const insersec: number[] = [];
    for (const ai of aSet) {
        if (bSet.has(ai)) {
            insersec.push(ai);
        }
    }
    return insersec;
}
