function jsonStringify(object: any): string {
    if(typeof object === 'string') {
        return `"${object}"`;
    }
    if(Array.isArray(object)) {
        return arrayStringify(object);
    }
    const isBaseCase = (
        typeof object === 'number'
        || typeof object === 'boolean' 
        || object == null
    );
    if(isBaseCase) {
        return `${object}`;
    }
    const parts = [];
    for(const key in object) {
        const value = jsonStringify(object[key]);
        parts.push(`"${key}":${value}`);
    }
    return `{${parts.join(",")}}`;
}

function arrayStringify(array: any[]) {
    return `[${array.map(jsonStringify).join(",")}]`;
}
