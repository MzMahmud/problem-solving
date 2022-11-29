/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
const isSubsequence = function (s, t) {
    let sIndex = 0;
    for(let i = 0;i < t.length;++i) {
        if(sIndex == s.length) {
            return true;
        }
        if(t[i] == s[sIndex]) {
            ++sIndex;
        }
    }
    return sIndex == s.length;
};
