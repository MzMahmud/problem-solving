MOD = int(1e9 + 7)

class Solution:
    def profitableSchemes(self, n, min_profit, groups, profits):
        cache = [[[None]*(min_profit + 1) for _ in range(n + 1) ] for _ in profits]
        
        def ways(i, group_size, profit):
            if i == len(profits):
                return 1 if profit >= min_profit else 0
            
            if cache[i][group_size][profit] is not None:
                return cache[i][group_size][profit]

            n_ways = ways(i + 1, group_size, profit)
            new_group_size = group_size + groups[i]
            if new_group_size <= n:
                n_ways += ways(i + 1, new_group_size, min(min_profit, profit + profits[i]))
            
            cache[i][group_size][profit] = n_ways % MOD
            return cache[i][group_size][profit]

        return ways(0, 0, 0)
