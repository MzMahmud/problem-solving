function tallestBillboard(rods: number[]) {
    let dp = new Map<number, number>();
    dp.set(0, 0);
    for (const r of rods) {
        const newDp = new Map(dp);
        for (const [diff, taller] of dp.entries()) {
            const shorter = taller - diff;
            const newTaller = newDp.get(diff + r) ?? 0;
            newDp.set(diff + r, Math.max(newTaller, taller + r));
            const newDiff = Math.abs(shorter + r - taller);
            const newTaller2 = Math.max(shorter + r, taller);
            newDp.set(newDiff, Math.max(newTaller2, newDp.get(newDiff) ?? 0));
        }
        dp = newDp;
    }
    return dp.get(0) ?? 0;
}
