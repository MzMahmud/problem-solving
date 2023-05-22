class Solution:
    # O(n + n log k + k)
    def topKFrequent(self, nums, k):
        # O(n) time
        freq = Counter(nums)
        top_k_elems = []
        # O(n log k) time
        for e, f in freq.items():
            if len(top_k_elems) < k or f >= top_k_elems[0][0]:
                heappush(top_k_elems, (f, e))
                if len(top_k_elems) > k:
                    heappop(top_k_elems)
        # O(k) time
        return [e for _, e in top_k_elems]
