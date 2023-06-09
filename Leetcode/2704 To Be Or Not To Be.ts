type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    function toBe(excected: any) {
        if (val === excected) return true;
        throw new Error("Not Equal");
    }
    function notToBe(excected: any) {
        if (val !== excected) return true;
        throw new Error("Equal");
    }
    return { toBe, notToBe };
}
