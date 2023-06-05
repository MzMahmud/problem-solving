function checkStraightLine(coordinates: number[][]): boolean {
    const [delX, delY] = getDelXDelY(coordinates[0], coordinates[1]);
    for (let i = 2; i < coordinates.length; i++) {
        const [delXi, delYi] = getDelXDelY(coordinates[0], coordinates[i]);
        const slopeNotEqual = (delX * delYi) != (delY * delXi);
        if (slopeNotEqual) {
            return false;
        }
    }
    return true;
}

function getDelXDelY(a: number[], b: number[]) {
    return [a[0] - b[0], a[1] - b[1]];
}
