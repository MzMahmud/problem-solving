type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function compactObject(obj: Obj): Obj {
    if (obj instanceof Array) {
        const compact: Obj = [];
        for (const val of obj) {
            if (isObj(val)) {
                compact.push(compactObject(val))
            } else if (val) {
                compact.push(val);
            }
        }
        return compact;
    }
    const compact: Obj = {};
    for (const key in obj) {
        const val = obj[key];
        if (isObj(val)) {
            compact[key] = compactObject(val);
        } else if (val) {
            compact[key] = val;
        }
    }
    return compact;
}

function isObj(value: unknown): value is Obj {
    if (value == null) return false;
    const valType = typeof value;
    return !["boolean", "number", "string"].includes(valType);
}
