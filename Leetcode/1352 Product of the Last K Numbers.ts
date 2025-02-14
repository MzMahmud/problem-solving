class ProductOfNumbers {
    private runningProd = [1];

    add(num: number): void {
        if (num === 0) {
            this.runningProd = [1];
        } else {
            const lastprod = this.runningProd[this.runningProd.length - 1];
            this.runningProd.push(lastprod * num);
        }
    }

    getProduct(k: number): number {
        const n = this.runningProd.length;
        const prefixIdx = n - 1 - k;
        if (prefixIdx < 0) return 0;
        return this.runningProd[n - 1] / this.runningProd[prefixIdx];
    }
}
