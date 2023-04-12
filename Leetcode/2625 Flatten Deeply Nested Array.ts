type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr:  MultiDimensionalArray, depth: number):  MultiDimensionalArray {
    if(depth === 0) {
        return arr;
    }
    const flattened: MultiDimensionalArray = [];
    for(const subArr of arr) {
        if(Array.isArray(subArr)) {
            flattened.push(...flat(subArr, depth - 1));
        } else {
            flattened.push(subArr);
        }
    }
    return flattened;
}
