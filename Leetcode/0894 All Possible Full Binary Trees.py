class Solution:
    def allPossibleFBT(self, n):
        full_binary_trees = [[], [TreeNode(0)]]

        for curr_n in range(2, n + 2):
            binary_trees = []

            for n_left in range(1, curr_n):
                n_right = curr_n - n_left - 1
                for left_tree in full_binary_trees[n_left]:
                    for righ_tree in full_binary_trees[n_right]:
                        binary_trees.append(TreeNode(0, left_tree, righ_tree))

            full_binary_trees.append(binary_trees)

        return full_binary_trees[n]
