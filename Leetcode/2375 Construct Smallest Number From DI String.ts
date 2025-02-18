function smallestNumber(pattern: string): string {
    const used = Array.from({ length: 10 }, () => false);

    function dfs(index: number, str: string): string {
        if (index >= pattern.length) return str;

        const lastNum = index < 0 ? 0 : Number(str[index]);
        const toIncrease = index < 0 || pattern[index] === "I";
        const del = toIncrease ? 1 : -1;

        for (
            let i = lastNum + del;
            toIncrease ? i < used.length : i > 0;
            i += del
        ) {
            if (used[i]) continue;
            used[i] = true;
            const num = dfs(index + 1, `${str}${i}`);
            if (num != "") return num;
            used[i] = false;
        }

        return "";
    }

    return dfs(-1, "");
}
