Array.prototype.groupBy = function(fn) {
    const groups = this.reduce(
        (map, item) => {
            const key = fn(item);
            if(!map.has(key)) {
                map.set(key, []);
            }
            map.get(key).push(item);
            return map;
        },
        new Map()
    );
    return Object.fromEntries(groups);
}

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
