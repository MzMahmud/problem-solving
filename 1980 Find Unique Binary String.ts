const findDifferentBinaryString = (nums: string[]) => nums.map((s, i) => s[i] === '0' ? '1' : '0').join("");
