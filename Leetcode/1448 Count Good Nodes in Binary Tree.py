class Solution:
    def goodNodes(self, root, max_path_val=float("-inf")):
        if root is None:
            return 0
        max_path_val = max(max_path_val, root.val)
        n_good_nodes = int(max_path_val == root.val)
        n_good_nodes += self.goodNodes(root.left, max_path_val)
        n_good_nodes += self.goodNodes(root.right, max_path_val)
        return n_good_nodes
