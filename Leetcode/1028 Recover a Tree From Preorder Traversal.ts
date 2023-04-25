// cleaner solition
function recoverFromPreorder(traversal: string): TreeNode | null {
    const path: TreeNode[] = [];
    const n = traversal.length;
    let i = 0; 
    while (i < n) {
        let depth = 0, val = 0;
        for (depth = 0; i < n && traversal[i] === '-'; i++) {
            depth++;
        }
        for (val = 0; i < n && traversal[i] !== '-'; i++) {
            val = 10 * val + Number(traversal[i]);
        }
        const node = new TreeNode(val);
        while(path.length && path.length > depth) {
            path.pop();
        }
        if (path.length) {
            const parent = path[path.length - 1];
            if (parent.left === null) {
                parent.left = node;
            } else if (parent.right === null) {
                parent.right = node;
            }
        }
        path.push(node);
    }
    return path.length? path[0] : null;
}
          
// my first solution
function recoverFromPreorder(traversal: string): TreeNode | null {
    const depthValues = getDepthValues(traversal);
    let root: TreeNode | null = null;
    const path: {node: TreeNode, depth: number} [] = [];
    for (const depthValue of depthValues) {
        const node = new TreeNode(depthValue.value);
        const depth = depthValue.depth;
        if (path.length === 0) {
            root = node;
        } else if (depth > path[path.length - 1].depth) {
            path[path.length - 1].node.left = node;
        } else {
            while(path && path[path.length - 1].depth >= depth) {
                path.pop();
            }
            if (path) {
                path[path.length - 1].node.right = node;
                path.pop();
            }
        }
        path.push({node, depth});
    }
    return root;
}

interface DepthValue {
    depth: number, 
    value: number,
}
    
function getDepthValues(traversal: string): DepthValue[] {
    const depths = traversal.split(/[0-9]+/);
    const values = traversal.split(/[-]+/);
    console.log({depths, values});
    const depthValues: DepthValue[] = [];
    for (let i = 0; i < values.length; i++) {
        depthValues.push({depth: depths[i].length, value: parseInt(values[i])});
    }
    return depthValues;
}
