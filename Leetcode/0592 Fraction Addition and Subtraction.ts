function fractionAddition(input: string): string {
    const len = input.length;
    let a: number | null = null;
    let sign = 1;
    const res: [number, number] = [0, 1];
    function add(c: number, d: number) {
        const [a, b] = res;
        res[0] = a * d + b * c;
        res[1] = b * d;
        const g = gcd(Math.abs(res[0]), res[1]);
        res[0] /= g;
        res[1] /= g;
    }
    for (let i = 0; i < len; i++) {
        const char = input[i];
        if (isDigit(char)) {
            let n = 0;
            while (i < len && isDigit(input[i])) {
                n = 10 * n + (+input[i]);
                i++;
            }
            i--;
            if (a == null) {
                a = n;
            } else {
                add(sign * a, n);
                a = null;
            }
        } else if (char != "/") {
            sign = char === "+" ? 1 : -1;
        }
    }
    return `${res[0]}/${res[1]}`;
}

function isDigit(char: string) {
    return typeof char === 'string' && char.length === 1 && char >= '0' && char <= '9';
}

function fractionAddition(input: string): string {
    const pattern = /[+-]?\d+\/\d+/g;
    const matches = input.match(pattern) ?? [];
    const sum = [0, 1];
    for (const frac of matches) {
        const [a, b] = sum;
        const [c, d] = frac.split("/").map(Number);
        sum[0] = a * d + b * c;
        sum[1] = b * d;
        const g = gcd(Math.abs(sum[0]), sum[1]);
        sum[0] /= g;
        sum[1] /= g;
    }
    return `${sum[0]}/${sum[1]}`;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
