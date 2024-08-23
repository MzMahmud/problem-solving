function solveEquation(equation: string): string {
    const [left, right] = equation.split("=");
    const leftCoeff = parse(left);
    const rightCoeff = parse(right);
    const [c, x] = [leftCoeff[0] - rightCoeff[0], rightCoeff[1] - leftCoeff[1]];
    if (x === 0) {
        return c === 0 ? "Infinite solutions" : "No solution";
    }
    return `x=${c / x}`;
}

function parse(input: string) {
    const coeff: [number, number] = [0, 0];
    for (const term of input.split(/(?=[+-])/)) { // with positive lookahead (?=)
        if (term.includes("x")) {
            let coeffX = term.replace("x", "");
            if (["", "+", "-"].includes(coeffX)) coeffX += "1";
            coeff[1] += Number(coeffX);
        } else {
            coeff[0] += Number(term);
        }
    }
    return coeff;
}

function parse(input: string) {
    const coeff: [number, number] = [0, 0];
    const len = input.length;
    let sign = 1;
    for (let i = 0; i < len; i++) {
        if (isDigit(input[i])) {
            let n = 0;
            while (i < len && isDigit(input[i])) {
                n = n * 10 + (+input[i]);
                i++;
            }
            if (i < len && input[i] == "x") {
                coeff[1] += sign * n;
            } else {
                coeff[0] += sign * n;
                i--;
            }
        } else if (input[i] === "+") {
            sign = 1;
        } else if (input[i] === "-") {
            sign = -1;
        } else if (input[i] === "x") {
            coeff[1] += sign;
        }
    }
    return coeff;
}

function isDigit(s: string) {
    return s.length == 1 && "0" <= s && s <= "9";
}
