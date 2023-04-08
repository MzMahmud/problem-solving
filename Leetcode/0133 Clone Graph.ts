function cloneGraph(node: Node | null): Node | null {
    if(node == null) {
        return null;
    }
    return clone(node, new Map());
}

function clone(node: Node, alreadyClonned: Map<number, Node>) {
    if(alreadyClonned.has(node.val)) {
        return alreadyClonned.get(node.val);
    }
    const clonnedNode = new Node(node.val, []);
    alreadyClonned.set(clonnedNode.val, clonnedNode);
    for(const neighbor of node.neighbors) {
        clonnedNode.neighbors.push(clone(neighbor, alreadyClonned));
    }
    return clonnedNode;
}
