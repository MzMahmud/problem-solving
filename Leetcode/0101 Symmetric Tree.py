class Solution:
    def isSymmetric(self, root):
        return is_symmetric(root, root)
        

def is_symmetric(left, right):
    if left is None or right is None:
        return left is right
    return (
        left.val == right.val 
        and is_symmetric(left.left, right.right) 
        and is_symmetric(left.right, right.left)
    )
