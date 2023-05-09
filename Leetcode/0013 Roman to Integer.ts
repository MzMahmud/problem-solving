const map: { [key: string]: number } = { 'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000, };

function romanToInt(s: string): number {
    let value = 0, lastValue = 0;
    for (let i = s.length - 1; i >= 0; i--) {
        const val = map[s[i]];
        if (val < lastValue) value -= val;
        else value += val;
        lastValue = val;
    }
    return value;
}
