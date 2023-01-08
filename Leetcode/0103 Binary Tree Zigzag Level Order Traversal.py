from queue import Queue

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def reverse_inplace(array):
    i, j = 0, len(array) - 1
    while i < j:
        array[i], array[j] = array[j], array[i]
        i += 1
        j -= 1


class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue = Queue()
        if root is not None:
            queue.put(root)

        zigzag_level, do_reverse = [], False

        while queue.qsize() > 0:
            n_nodes_in_level, level = queue.qsize(), []
            for _ in range(n_nodes_in_level):
                tree_node = queue.get()

                level.append(tree_node.val)

                if tree_node.left is not None:
                    queue.put(tree_node.left)

                if tree_node.right is not None:
                    queue.put(tree_node.right)

            if do_reverse:
                reverse_inplace(level)

            zigzag_level.append(level)
            do_reverse = not do_reverse

        return zigzag_level
