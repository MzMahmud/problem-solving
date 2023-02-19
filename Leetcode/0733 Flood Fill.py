class Solution:
    def floodFill(self, image, sr, sc, color):
        flood_fill(sr, sc, image, image[sr][sc], color)
        return image


def flood_fill(i, j, image, target_color, fill_color):
    n, m = len(image), len(image[0])
    in_bound = (0 <= i < n) and (0 <= j < m)
    if not in_bound or image[i][j] != target_color or image[i][j] == fill_color:
        return

    image[i][j] = fill_color

    flood_fill(i-1, j, image, target_color, fill_color)
    flood_fill(i, j + 1, image, target_color, fill_color)
    flood_fill(i + 1, j, image, target_color, fill_color)
    flood_fill(i, j-1, image, target_color, fill_color)
