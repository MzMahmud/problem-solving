function getHappyString(n: number, k: number): string {
    const values = "abc";
    let count = 0;
    let kThStr = "";
    function dfs(i: number, s: string) {
        if (i >= n) {
            if (++count == k) {
                kThStr = s;
            }
            return;
        }
        const lastChar = s.length === 0 ? "" : s[s.length - 1];
        for (const ch of values) {
            if (ch !== lastChar && count < k) {
                dfs(i + 1, `${s}${ch}`);
            }
        }
    }
    dfs(0, "");
    return kThStr;
}
