function countDistinctIntegers(nums: number[]): number {
  const uniqueNums = new Set<number>(nums);
  for (const num of nums) {
    uniqueNums.add(reverse(num));
  }
  return uniqueNums.size;
}

function reverse(n: number) {
  let rev = 0;
  for(; n > 0; n = Math.floor(n / 10)) {
    rev = rev * 10 + n % 10;
  }
  return rev;
}
