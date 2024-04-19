class TimeLimitedCache {
    private cache = new Map<number, { id: ReturnType<typeof setTimeout>, value: number }>();

    constructor() { }

    set(key: number, value: number, duration: number): boolean {
        const prevId = this.cache.get(key)?.id;
        if (prevId != null) clearTimeout(prevId);
        const id = setTimeout(() => this.cache.delete(key), duration);
        this.cache.set(key, { id, value });
        return prevId != null;
    }

    get(key: number): number {
        return this.cache.get(key)?.value ?? -1;
    }

    count(): number {
        return this.cache.size;
    }
}
