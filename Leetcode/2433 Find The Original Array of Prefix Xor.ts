function findArray(pref: number[]): number[] {
    for (let i = 0, prev = 0; i < pref.length; i++) {
        pref[i] ^= prev;
        prev ^= pref[i]; 
    }
    return pref;
}
