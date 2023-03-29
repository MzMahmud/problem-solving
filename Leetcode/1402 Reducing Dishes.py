class Solution:
    def maxSatisfaction(self, satisfactions):
        n = len(satisfactions)
        cache = [[None for _ in range(n + 1)] for _ in range(n)]
        satisfactions.sort()
        return max_satisfaction_dp(0, 1, satisfactions, cache)

# O(n^2) time dp solution
def max_satisfaction_dp(index, time, satisfactions, cache):
    if index == len(satisfactions):
        return 0
    
    if cache[index][time] is not None:
        return cache[index][time]
    
    if_cooked = (
        time * satisfactions[index]
        + max_satisfaction_dp(index + 1, time + 1, satisfactions, cache)
    )
    
    if_not_cooked = max_satisfaction_dp(index + 1, time, satisfactions, cache)

    cache[index][time] = max(if_cooked, if_not_cooked)
    return cache[index][time]
  
  
  # O(n log n) time greedy solution
  def max_satisfaction_greedy(satisfactions):
    satisfactions.sort(reverse=True)
    prefix_sum, max_like_time  = 0, 0
    for satisfaction in satisfactions:
        prefix_sum += satisfaction
        if prefix_sum < 0:
            break
        max_like_time += prefix_sum
    return max_like_time
