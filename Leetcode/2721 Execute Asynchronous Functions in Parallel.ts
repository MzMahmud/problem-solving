async function promiseAll<T>(fns: (() => Promise<T>)[]): Promise<T[]> {
    return new Promise((resolve, reject) => {
        const resolved = new Array<T>(fns.length);
        let remaining = fns.length;
        for (let i = 0; i < fns.length; i++) {
            fns[i]()
                .then(t => {
                    resolved[i] = t;
                    if (--remaining === 0) resolve(resolved);
                })
                .catch(error => reject(error));
        }
    });
}
