class SnapshotArray {
    private data: number[][];
    private snapId = 0;

    constructor(length: number) {
        this.data = new Array<number[]>(length);
        for (let i = 0; i < this.data.length; i++) {
            this.data[i] = [0];
        }
    }
    
    private getLastRecordedVal(index: number) {
        return this.data[index][this.data[index].length -1];
    }
	

    set(index: number, val: number) {
        const lastVal = this.getLastRecordedVal(index);
        this.data[index][this.snapId] = val;
        for (let prev = this.snapId - 1; prev > 0 && this.data[index][prev] === undefined; prev--) {
            this.data[index][prev] = lastVal;
        }
    }
    
    snap() {
        return this.snapId++;
    }
    
    get(index: number, snapId: number) {
        if(snapId >= this.data[index].length) {
            return this.getLastRecordedVal(index);
        }
        return this.data[index][snapId] ?? 0;
    }
}
