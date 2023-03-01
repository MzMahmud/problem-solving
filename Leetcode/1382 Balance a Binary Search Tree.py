class Solution:
    def balanceBST(self, root):
        inorder = get_inorder(root, [])
        return get_balaced_bst(inorder, 0, len(inorder) - 1)


def get_inorder(root, inorder):
    if root is not None:
        get_inorder(root.left, inorder)
        inorder.append(root)
        get_inorder(root.right, inorder)
    return inorder


def get_balaced_bst(node_array, start, end):
    if start > end:
        return None
    mid = start + (end - start) // 2
    root = node_array[mid]
    root.left = get_balaced_bst(node_array, start, mid - 1)
    root.right = get_balaced_bst(node_array, mid + 1, end)
    return root
