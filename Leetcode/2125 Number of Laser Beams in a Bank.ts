function numberOfBeams(bank: string[]): number {
    let lastNonZeroLasers = 0;
    let nBeams = 0;
    for (const row of bank) {
        let lasers = 0
        for (const c of row) {
            if (c === '1') {
                lasers++;
            }
        }
        if (lasers !== 0) {
            nBeams += lastNonZeroLasers * lasers;
            lastNonZeroLasers = lasers;
        }
    }
    return nBeams;
}
