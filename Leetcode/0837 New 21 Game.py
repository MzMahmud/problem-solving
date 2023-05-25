class Solution:
    def new21Game(self, n, k, max_pts):
        if k == 0:
            return 1
        prob = [0] * k
        window_sum = min(max_pts, n - k + 1)
        for i in range(k - 1, -1, -1):
            prob[i] = window_sum / max_pts
            exit_index, exit_value = i + max_pts, 0
            if exit_index < k:
                exit_value = prob[exit_index]
            elif exit_index <= n:
                exit_value = 1
            window_sum += prob[i] - exit_value
        return prob[0]
