class Solution:
    def findTilt(self, root):
        tilt_sum = 0

        def dfs(root):
            nonlocal tilt_sum

            if root is None:
                return 0

            left_sum = dfs(root.left)
            right_sum = dfs(root.right)
            tilt_sum += abs(left_sum - right_sum)
            return left_sum + root.val + right_sum

        dfs(root)
        return tilt_sum
