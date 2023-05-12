function chunk(arr: any[], size: number): any[][] {
    const chunks: any[][] = [];
    let lastChunk: any[] = [];
    for (const e of arr) {
        if (lastChunk.length === size) {
            chunks.push(lastChunk);
            lastChunk = [];
        }
        lastChunk.push(e);
    }
    if (lastChunk.length) {
        chunks.push(lastChunk);
    }
    return chunks;
}
