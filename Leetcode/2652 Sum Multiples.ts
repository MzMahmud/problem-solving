function sumOfMultiples(n: number): number {
  return sumMultiples(n, 3) + sumMultiples(n, 5) + sumMultiples(n, 7)
         - sumMultiples(n, 3 * 5) - sumMultiples(n, 3 * 7) - sumMultiples(n, 5 * 7)
         + sumMultiples(n, 3 * 5 * 7);
}

function sumMultiples(n: number, k: number): number {
    n = Math.floor(n / k);
    return k * n * (n + 1) / 2;
}
