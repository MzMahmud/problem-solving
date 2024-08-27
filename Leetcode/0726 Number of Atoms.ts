function countOfAtoms(s: string) {
    const n = s.length;
    const atomCounts = [new Map<string, number>()];
    for (let i = 0; i < n;) {
        if (s[i] === "(") {
            atomCounts.push(new Map());
            i++;
        } else if (s[i] === ")") {
            const { num, nextI } = getNumber(s, i + 1);
            const atomCount = atomCounts.pop()!;
            const prevAtomCounts = atomCounts.at(-1)!;
            for (const [atom, count] of atomCount) {
                const updated = count * num + (prevAtomCounts.get(atom) ?? 0);
                prevAtomCounts.set(atom, updated);
            }
            i = nextI;
        } else {
            const atomCount = atomCounts.at(-1)!;
            let atom = s[i++];
            while (i < n && isLower(s[i])) atom += s[i++];
            const { num, nextI } = getNumber(s, i);
            const count = (atomCount.get(atom) ?? 0) + num;
            atomCount.set(atom, count);
            i = nextI;
        }
    }
    return [...atomCounts[0].entries()]
        .sort()
        .map(([atom, count]) => `${atom}${count == 1 ? "" : count}`)
        .join("");
}

function getNumber(s: string, i: number) {
    let num = 0;
    while (i < s.length && isDigit(s[i])) {
        num = num * 10 + Number(s[i]);
        i++;
    }
    if (num == 0) num = 1;
    return { num, nextI: i };
}

function isDigit(s: string) {
    return /^[0-9]$/.test(s);
}

function isLower(s: string) {
    return /^[a-z]$/.test(s);
}
