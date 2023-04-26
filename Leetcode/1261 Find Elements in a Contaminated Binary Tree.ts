// O(1) space
class FindElements {
    private root: TreeNode | null;
    
    // O(1) time
    constructor(root: TreeNode | null) {
        this.root = root;
    }

    // O(log target) time, O(log target) space
    find(target: number): boolean {
        const path = this.findPath(target);
        let curr: TreeNode | null = this.root, i = 0;
        while (curr != null && i < path.length) {
            curr = path[i] === "L" ? curr.left : curr.right;
            i++;
        }
        return curr != null && i == path.length;
    }

    private findPath(value: number): ("L" | "R")[] {
        const path: ("L" | "R")[] = [];
        while(value > 0) {
            path.push(value % 2 === 1? "L" : "R");
            value = (value - 1) >> 1;
        }
        path.reverse();
        return path;
    }
}
          
// O(n) space
class FindElements {
    private values = new Set<number>();
    
    // O(n) time      
    constructor(root: TreeNode | null) {
        this.dfs(root, 0);
    }

    // O(1) time
    find(target: number): boolean {
        return this.values.has(target);
    }

    private dfs(root: TreeNode | null, index: number) {
        if (root !== null) {
            this.values.add(index);
            this.dfs(root.left, 2 * index + 1);
            this.dfs(root.right, 2 * index + 2);
        }
    }
}
