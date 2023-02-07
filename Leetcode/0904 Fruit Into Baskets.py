class Solution:
    BASKET_SIZE = 2

    def totalFruit(self, fruits):
        left, right, max_window_len = 0, 0, 0
        last_index = {}

        for right, fruit in enumerate(fruits):
            if fruit not in last_index and len(last_index) == Solution.BASKET_SIZE:
                min_last_index_fruit = min(last_index, key=last_index.get)
                left = last_index[min_last_index_fruit] + 1
                last_index.pop(min_last_index_fruit)

            last_index[fruit] = right
            window_len = right - left + 1
            max_window_len = max(max_window_len, window_len)

        return max_window_len
