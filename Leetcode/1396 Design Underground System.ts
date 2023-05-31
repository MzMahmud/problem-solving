class UndergroundSystem {
    private checkInTimeById: Map<number, [string, number]> = new Map();
    private travelLogs: Map<string, [number, number]> = new Map();
    
    constructor() {}

    checkIn(id: number, stationName: string, t: number): void {
        this.checkInTimeById.set(id, [stationName, t]);
    }

    checkOut(id: number, stationName: string, t: number): void {
        const [fromStation, fromTime] = this.checkInTimeById.get(id) as [string, number];
        const journeyKey = this.getJourneyKey(fromStation, stationName);
        const travelLog = this.travelLogs.get(journeyKey) ?? [0, 0];
        travelLog[0] += t - fromTime;
        travelLog[1]++;
        this.travelLogs.set(journeyKey, travelLog);
    }

    getAverageTime(startStation: string, endStation: string): number {
        const travelLog = this.travelLogs.get(this.getJourneyKey(startStation, endStation)) ?? [0, 1];
        return travelLog[0] / travelLog[1];
    }

    private getJourneyKey(fromStation: string, toStation: string) {
        return `${fromStation}-${toStation}`;
    }
}
