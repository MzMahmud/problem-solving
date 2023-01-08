class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i, j, max_area = 0, len(heights) - 1, 0
        while i < j:
            width = j - i
            if heights[i] < heights[j]:
                max_area = max(max_area, heights[i] * width)
                i += 1
            else:
                max_area = max(max_area, heights[j] * width)
                j -= 1
        return max_area
