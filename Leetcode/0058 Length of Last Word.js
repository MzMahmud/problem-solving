/**
 * @param {string} s
 * @return {number}
 */
const lengthOfLastWord = function (s) {
    let beginIndex = s.length - 1;
    while(beginIndex >= 0 && s[beginIndex] == ' ') {
        --beginIndex;
    }
    let lenLastWord = 0;
    while(beginIndex >= 0 && s[beginIndex] != ' ') {
        --beginIndex;
        ++lenLastWord;
    }
    return lenLastWord;
};
