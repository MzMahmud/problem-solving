function countDigits(num: number): number {
  let count = 0;
  for (let n = num; n > 0; n = Math.floor(n / 10)) {
    const d = n % 10;
    if (num % d === 0) {
      count++;
    }
  }
  return count;
}
