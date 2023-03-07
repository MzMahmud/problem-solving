class Solution:
    def flipAndInvertImage(self, image):
        for row in image:
            i, j = 0, len(row) - 1
            while i <= j:
                end = 0 if row[j] == 1 else 1
                row[j] = 0 if row[i] == 1 else 1
                row[i] = end
                i += 1
                j -= 1
        return image
