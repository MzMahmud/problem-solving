function* fibGenerator(): Generator<number, any, number> {
    yield 0;
    yield 1;
    let a = 0, b = 1, c = 0;
    while(true) {
        yield c = a + b;
        a = b;
        b = c;    
    }
}

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
