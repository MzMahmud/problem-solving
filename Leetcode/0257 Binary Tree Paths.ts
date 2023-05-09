function binaryTreePaths(root: TreeNode | null): string[] {
    const paths: string[] = [];
    function dfs(root: TreeNode | null, path: string[]) {
        if (root === null) return;
        path.push(`${root.val}`);
        if (root.left === null && root.right === null) {
            paths.push(path.join('->'));
        }
        dfs(root.left, path);
        dfs(root.right, path);
        path.pop();
    }
    dfs(root, []);
    return paths;
}
