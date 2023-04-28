// Math Solution
// good explanation https://leetcode.com/problems/count-sorted-vowel-strings/solutions/1021180/python-start-and-bars-explained/
function countVowelStrings(n: number): number {
  // C(n + 4, 4)
  return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
}

// DP Solution
const N_VOWELS = 5;

function countVowelStrings(n: number): number {
  const cache = new Array<number[]>(n + 2);
  for (let i = 0; i < cache.length; i++) {
    cache[i] = new Array<number>(N_VOWELS).fill(-1);
  }
  return vowelStrings(n + 1, 0, cache);
}


function vowelStrings(n: number, i: number, cache: number[][]): number {
  if (n === 1) {
    return 1;
  }
  if (cache[n][i] !== -1) {
    return cache[n][i];
  }
  cache[n][i] = 0;
  for (let j = i; j < N_VOWELS; j++) {
    cache[n][i] += vowelStrings(n - 1, j, cache);
  }
  return cache[n][i];
}
