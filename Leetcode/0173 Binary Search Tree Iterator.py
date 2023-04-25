class BSTIterator:
    def __init__(self, root):
        self.stack = []
        self.__populate_stack(root)

    def next(self):
        top = self.stack.pop()
        self.__populate_stack(top.right)
        return top.val

    def hasNext(self):
        return len(self.stack) != 0

    def __populate_stack(self, root):
        while root:
            self.stack.append(root)
            root = root.left
