class Solution:
    def averageOfSubtree(self, root):
        node_count = 0

        def postorder(root):
            nonlocal node_count

            if root is None:
                return 0, 0

            left_sum, left_nodes,  = postorder(root.left)
            right_sum, right_nodes = postorder(root.right)

            tree_sum = left_sum + root.val + right_sum
            n_nodes = left_nodes + 1 + right_nodes
            average = tree_sum // n_nodes
            if root.val == average:
                node_count += 1

            return tree_sum, n_nodes

        postorder(root)
        return node_count
