function canPlaceFlowers(flowerbed: number[], n: number): boolean {
    let count = 0;
    for (let i = 0; i < flowerbed.length; i++) {
        if (flowerbed[i] == 0) {
            const emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
            const emptyRightPlot = (i == flowerbed.length - 1) || (flowerbed[i + 1] == 0);
            if (emptyLeftPlot && emptyRightPlot) {
                flowerbed[i] = 1;
                count++;
            }
        }
    }
    return count >= n;
};
