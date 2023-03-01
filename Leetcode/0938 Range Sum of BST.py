class Solution:
    def rangeSumBST(self, root, low, high):
        if root is None or low > high:
            return 0

        range_sum = root.val if low <= root.val <= high else 0

        if not (root.val < low):
            range_sum += self.rangeSumBST(root.left, low, min(root.val, high))
        if not (root.val > high):
            range_sum += self.rangeSumBST(root.right, max(root.val, low), high)

        return range_sum
