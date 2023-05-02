function findTheWinner(n: number, k: number): number {
    return josephus(n, k) + 1;
}

function josephus(n: number, k: number): number {
    return n === 1 ? 0 : (josephus(n - 1, k) + k) % n;
}
