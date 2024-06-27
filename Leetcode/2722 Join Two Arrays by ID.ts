type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type ArrayType = { "id": number } & Record<string, JSONValue>;

function join(a: ArrayType[], b: ArrayType[]): ArrayType[] {
    const objById = new Map(a.map(obj => [obj.id, obj]));
    for (const bObj of b) {
        const aObj = objById.get(bObj.id) ?? {};
        objById.set(bObj.id, { ...aObj, ...bObj });
    }
    const ids = [...objById.keys()].sort((a, b) => a - b);
    return ids.map(id => objById.get(id)!);
}
