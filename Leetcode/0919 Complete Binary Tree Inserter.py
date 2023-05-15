class CBTInserter:
    def __init__(self, root):
        self.root = root
        self.parents = deque()
        queue = deque([root])
        while queue:
            node = queue.popleft()
            if not node.left or not node.right:
                self.parents.append(node)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
    def insert(self, val):
        parent = self.parents[0]
        self.parents.append(TreeNode(val))
        if not parent.left:
            parent.left = self.parents[-1]
        else:
            parent.right = self.parents[-1]
            self.parents.popleft()
        return parent.val
        
    def get_root(self):
        return self.root
