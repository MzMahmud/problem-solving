// O(n log n) time sorting + two pointer solution
function numRescueBoats(people: number[], limit: number): number {
    // O(n log n)
    people.sort((a, b) => a - b);
    let i = 0, j = people.length - 1, nBoats = 0;
    // O(n)
    while(i <= j) {
        const totalWeight = people[i] + people[j];
        if(totalWeight <= limit) {
            i++;
        }
        nBoats++;
        j--;
    }
    return nBoats;
}
