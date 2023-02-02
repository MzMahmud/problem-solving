class Solution:
    def __init__(self):
        self.target_path_sum_count = None

    def pathSum(self, root, target_sum):
        self.target_path_sum_count = 0
        path_sum_counts = {0: 1}
        self.dfs(root, 0, target_sum, path_sum_counts)
        return self.target_path_sum_count

    def dfs(self, root, current_path_sum, target_sum, path_sum_counts):
        if root is None:
            return

        current_path_sum += root.val
        required_path_sum = current_path_sum - target_sum
        self.target_path_sum_count += path_sum_counts.get(required_path_sum, 0)
        path_sum_counts[current_path_sum] = path_sum_counts.get(current_path_sum, 0) + 1

        self.dfs(root.left, current_path_sum, target_sum, path_sum_counts)
        self.dfs(root.right, current_path_sum, target_sum, path_sum_counts)
        path_sum_counts[current_path_sum] -= 1
