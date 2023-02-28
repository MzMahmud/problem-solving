class Solution:
    def increasingBST(self, root):
        self.prev = None
        self.first = None

        self.rearrange(root)

        if self.prev:
            self.prev.left = None
            self.prev.right = None

        return root if self.first is None else self.first

    def rearrange(self, root):
        if root is None:
            return

        self.rearrange(root.left)

        if self.prev:
            self.prev.left = None
            self.prev.right = root

        if self.first is None:
            self.first = self.prev

        self.prev = root

        self.rearrange(root.right)
