function interpret(command: string): string {
    const output: string[] = [];
    let i = 0;
    while (i < command.length) {
        if (command[i] === '(') {
            if (command[i + 1] === ')') {
                output.push('o');
                i++;
            } else {
                while(i < command.length && command[i] !== ')') i++;
                output.push('al');
            }
        } else {
            output.push('G');
        }
        i++;
    }
    return output.join('');
}
