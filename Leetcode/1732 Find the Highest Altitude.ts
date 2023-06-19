function largestAltitude(gains: number[]): number {
    let altitude = 0, maxAltitude = 0;
    for (const gain of gains) {
        altitude += gain;
        maxAltitude = Math.max(maxAltitude, altitude);
    }
    return maxAltitude;
}
