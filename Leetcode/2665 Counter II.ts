type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

// class solution
class Counter implements ReturnObj {
    private curr: number;

    constructor(private init: number) {
        this.curr = this.init;
    }
    
    public increment(): number {
        return ++this.curr;
    }
    
    public decrement(): number {
        return --this.curr;
    }
    
    public reset(): number {
        return this.curr = this.init;
    }
}

function createCounter(init: number): ReturnObj {
    return new Counter(init);
}

// object solution
function createCounter(init: number): ReturnObj {
    let curr = init;
    return {
        increment: () => ++curr,
        decrement: () => --curr,
        reset: () => curr = init,
    };
}
