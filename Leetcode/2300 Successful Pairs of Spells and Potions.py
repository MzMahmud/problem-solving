class Solution:
    # O(n log n + m log m) time, sorting + two pointer solution
    def successfulPairs(self, spells, potions, success):
        n, m = len(spells), len(potions)
        # O(m log m)
        potions.sort()
        # O(n log n)
        spells_indices = list(range(n))
        spells_indices.sort(key=lambda index: spells[index], reverse=True)
        pairs,i , j = [0] * n, 0, 0
        # O(n + m)
        while i < n and j < m:
            spell_index = spells_indices[i]
            factor = ceil(success / spells[spell_index])
            while j < m and potions[j] < factor:
                j += 1
            pairs[spell_index] = m - j
            i += 1
        return pairs
        # final O(n log n + m log m)
        
        
    # O(m log m + n log m) time, sort + binary search solution
    def successfulPairs(self, spells, potions, success):
        # O(m log m)
        potions.sort()
        # O(log m)
        def get_n_successful_pairs(spell):
            factor = ceil(success / spell)
            lower_bound = get_lower_bound(potions, factor)
            return len(potions) - lower_bound
        # O(n log m)
        return list(map(get_n_successful_pairs, spells))    
        # final O(m log m + n log m)       


def get_lower_bound(numbers, target):
    lo, hi = 0, len(numbers) - 1
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if numbers[mid] >= target:
            hi = mid - 1
        else:
            lo = mid + 1
    return lo
