function leafSimilar(root1: TreeNode | null, root2: TreeNode | null): boolean {
    const leaves1 = getLeaves(root1, []);
    const leaves2 = getLeaves(root2, []);
    if (leaves1.length !== leaves2.length) {
        return false;
    }
    for (let i = 0; i < leaves1.length; i++) {
        if (leaves1[i] !== leaves2[i]) {
            return false;
        }
    }
    return true;
}

function getLeaves(root: TreeNode | null, leaves: number[]) {
    if (root !== null) {
        if (root.left === null && root.right === null) {
            leaves.push(root.val);
        }
        getLeaves(root.left, leaves);
        getLeaves(root.right, leaves);
    }
    return leaves;
}

// O(1) space solution
function leafSimilar(root1: TreeNode | null, root2: TreeNode | null): boolean {
    let head1 = getLeavesListHead(root1), head2 = getLeavesListHead(root2);
    while (head1 !== null && head2 !== null) {
        if (head1.val !== head2.val) {
            return false;
        }
        head1 = head1.right;
        head2 = head2.right;
    }
    return head1 === null && head2 === null;
}

function getLeavesListHead(root: TreeNode | null): TreeNode | null {
    let head: TreeNode | null = null, prev: TreeNode | null = null;
    function dfs(root: TreeNode | null) {
        if (root === null) {
            return;
        }
        if (root.left === null && root.right === null) {
            if (prev === null) {
                head = prev = root;
            } else {
                prev = prev.right = root;
            }
        }
        dfs(root.left);
        dfs(root.right);
    }
    dfs(root);
    return head;
}
