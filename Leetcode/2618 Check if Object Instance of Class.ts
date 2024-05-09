function checkIfInstanceOf(obj: any, classFunction: any): boolean {
    const prototype = classFunction?.prototype;
    while (obj != null) {
        if (obj === prototype) return true;
        obj = Object.getPrototypeOf(obj);
    }
    return false;
}
