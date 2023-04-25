class BSTIterator {
    private stack: TreeNode[] = [];
    
    constructor(root: TreeNode | null) {
        this.populateStack(root);
    }

    next(): number {
        const top = this.stack.pop() as TreeNode;
        this.populateStack(top.right);
        return top.val;
    }

    hasNext(): boolean {
        return this.stack.length !== 0;
    }

    private populateStack(root: TreeNode | null) {
        while (root !== null) {
            this.stack.push(root);
            root = root.left;
        }
    }
}
