function countOfAtoms(formula: string) {
    const { atomCount } = countAtoms(formula, 0);
    return [...atomCount.entries()]
        .sort()
        .map(([atom, count]) => count == 1 ? atom : `${atom}${count}`)
        .join("");
}

function countAtoms(formula: string, i: number) {
    const atomCount = new Map<string, number>();
    const n = formula.length;
    while (i < n) {
        const char = formula[i];
        if (char == "(") {
            const { atomCount: innerCount, nextI } = countAtoms(formula, i + 1);
            i = nextI;
            for (const [atom, count] of innerCount) {
                const newCount = (atomCount.get(atom) ?? 0) + count;
                atomCount.set(atom, newCount);
            }
        } else if (char == ")") {
            i++;
            let num = 0;
            while (i < n && isDigit(formula[i])) num = num * 10 + Number(formula[i++]);
            if (num == 0) num = 1;
            for (const [atom, count] of atomCount) atomCount.set(atom, count * num);
            break;
        } else {
            i++;
            let atom = char;
            while (i < n && isLower(formula[i])) atom += formula[i++];
            let count = 0;
            while (i < n && isDigit(formula[i])) count = count * 10 + Number(formula[i++]);
            if (count == 0) count = 1;
            count += (atomCount.get(atom) ?? 0);
            atomCount.set(atom, count);
        }
    }
    return { atomCount, nextI: i };
}

const isDigit = (s: string) => /^[0-9]$/.test(s);
const isLower = (s: string) => /^[a-z]$/.test(s);
