class Solution:
    def constructMaximumBinaryTree(self, nums):
        return get_max_tree(nums, 0, len(nums))


def get_max_index(array, start, end):
    max_index = None
    for i in range(start, end):
        if max_index is None or array[i] > array[max_index]:
            max_index = i
    return max_index


def get_max_tree(array, start, end):
    if start >= end:
        return None

    max_index = get_max_index(array, start, end)
    root = TreeNode(array[max_index])
    root.left = get_max_tree(array, start, max_index)
    root.right = get_max_tree(array, max_index + 1, end)

    return root
