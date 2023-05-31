class Bitset {
    oneIndices = new Set<number>();
    zeroIndices = new Set<number>();

    constructor(private size: number) {
        for (let i = 0; i < this.size; i++) {
            this.zeroIndices.add(i);
        }
    }

    fix(idx: number): void {
        this.zeroIndices.delete(idx);
        this.oneIndices.add(idx);
    }

    unfix(idx: number): void {
        this.oneIndices.delete(idx);
        this.zeroIndices.add(idx);
    }

    flip(): void {
        const temp = this.oneIndices;
        this.oneIndices = this.zeroIndices;
        this.zeroIndices = temp;
    }

    all(): boolean {
        return this.oneIndices.size === this.size;
    }

    one(): boolean {
        return this.oneIndices.size >= 1;
    }

    count(): number {
        return this.oneIndices.size;
    }

    toString(): string {
        const bits = new Array<number>(this.size);
        for (let i = 0; i < this.size; i++) {
            bits[i] = this.oneIndices.has(i) ? 1 : 0;
        }
        return bits.join('');
    }
}
