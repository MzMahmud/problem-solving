const MOD = 1_000_000_007;
const N_CHARS = 26;

function numWays(words: string[], target: string): number {
  const countCharIndex = getCountCharIndex(words, target);
  const cache = new Array<number[]>(target.length);
  for (let i = 0; i < cache.length; i++) {
    cache[i] = new Array<number>(words[0].length).fill(-1);
  }
  function ways(i: number, k: number): number {
    if (i === target.length) {
      return 1;
    }
    if (k === words[0].length) {
      return 0;
    }
    if (cache[i][k] !== -1) {
      return cache[i][k];
    }
    cache[i][k] = ways(i, k + 1) % MOD;
    const charIndex = target.charCodeAt(i) - 'a'.charCodeAt(0);
    cache[i][k] += (countCharIndex[charIndex][k] * ways(i + 1, k + 1)) % MOD;
    return cache[i][k] % MOD;
  }
  return ways(0, 0);
}

function getCountCharIndex(words: string[], target: string) {
  const countCharIndex = new Array<number[]>(N_CHARS);
  for (let i = 0; i < countCharIndex.length; i++) {
    countCharIndex[i] = new Array<number>(words[0].length).fill(0);
  }
  for (let k = 0; k < words[0].length; k++) {
    for (const word of words) {
      const charIndex = word.charCodeAt(k) - 'a'.charCodeAt(0);
      countCharIndex[charIndex][k]++;
    }
  }
  return countCharIndex;
}
