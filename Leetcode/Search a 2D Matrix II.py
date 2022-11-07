class Solution(object):
    # O(n + m) Time | O(1) Space
    def searchMatrix(self, matrix, target):
        n, m = len(matrix), len(matrix[0]) 
        i, j = 0, m - 1
        while (0 <= i < n) and (0 <= j < m):
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                i += 1
            else:
                j -= 1
        return False
