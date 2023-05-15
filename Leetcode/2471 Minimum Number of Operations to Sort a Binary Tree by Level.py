class Solution:
    def minimumOperations(self, root):
        q = deque([root])
        n_swaps = 0
        while q:
            level = []
            for _ in range(len(q)):
                node = q.popleft()
                level.append(node.val)
                if node.left: 
                    q.append(node.left)
                if node.right: 
                    q.append(node.right)
            n_swaps += min_swaps_to_sort(level)
        return n_swaps

def min_swaps_to_sort(nums):
    n = len(nums)
    idx = list(range(n))
    idx.sort(key=lambda i: nums[i])
    n_swaps = 0
    for i in range(n):
        while idx[i] != i:
            j = idx[i]
            idx[i], idx[j] = idx[j], idx[i]
            n_swaps += 1
    return n_swaps
