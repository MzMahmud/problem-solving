function tree2str(root: TreeNode | null): string {
    if (root === null) return '';
    const left = tree2str(root.left);
    const right = tree2str(root.right);
    if (left === '' && right === '') return `${root.val}`;
    if (left === '') return `${root.val}()(${right})`;
    if (right === '') return `${root.val}(${left})`;
    return `${root.val}(${left})(${right})`;
}
