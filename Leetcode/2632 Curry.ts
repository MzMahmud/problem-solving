function curry(fn: Function): Function {
    return function curried(...args: any[]) {
        if (args.length >= fn.length) {
            return fn(...args);
        }
        return (...nextArgs: any[]) => curried(...args, ...nextArgs);
    }
}
