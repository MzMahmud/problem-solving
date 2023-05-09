function preorder(root: Node | null, preOrder: number[] = []): number[] {
    if (root !== null) {
        preOrder.push(root.val);
        for (const child of root.children) {
            preorder(child, preOrder);
        }
    }
    return preOrder;
}
