function postorder(root: Node | null, postOrder: number[] = []): number[] {
    if (root !== null) {
        for (const child of root.children) {
            postorder(child, postOrder);
        }
        postOrder.push(root.val);
    }
    return postOrder;
}
