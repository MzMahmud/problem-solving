const ignore = ["", ".", ".."]

function simplifyPath(path: string): string {
    const stack: string[] = [];
    const dirs = path.split("/");
    for (const dir of dirs) {
        if(dir === ".." && stack.length > 0) {
            stack.pop();
        } else if(!ignore.includes(dir)){
            stack.push(dir);
        }
    }
    return `/${stack.join("/")}`;
}
