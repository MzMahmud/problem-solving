const replaceElements = function (array) {
    let maxElement = array[array.length - 1];
    array[array.length - 1] = -1;

    for(let i = array.length - 2;i >= 0;--i) {
        const nextMaxElem = Math.max(maxElement, array[i]);
        array[i] = maxElement;
        maxElement = nextMaxElem;
    }
    return array;
};
