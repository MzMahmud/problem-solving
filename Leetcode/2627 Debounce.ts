type AnyFunction = (...args: any[]) => any;

function debounce<Fn extends AnyFunction>(fn: Fn, t: number) {
    let timer: ReturnType<typeof setTimeout>;
    return function (...args: Parameters<Fn>) {
        clearTimeout(timer);
        timer = setTimeout(() => fn(...args), t);
    }
}
