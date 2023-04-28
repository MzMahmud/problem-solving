// a number which is all sum of 3 has only 0 or 1 in its base 3 form
function checkPowersOfThree(n: number): boolean {
    while (n > 0) {
        if (n % 3 === 2) {
            return false;
        }
        n = Math.floor(n / 3);
    }
    return true;
}
