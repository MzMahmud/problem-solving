class Solution:
    # O(n) time, O(n) space
    def convert(self, string, n_rows):
        if n_rows == 1 or n_rows >= len(string):
            return string

        lines = [[] for _ in range(n_rows)]
        direction, line, last_line = 1, 0, n_rows - 1
        direction_change_state = [(0, -1), (last_line, 1)]

        for char in string:
            lines[line].append(char)
            if (line, direction) in direction_change_state:
                direction *= -1
            line += direction

        lines_joined = map("".join, lines)
        all_lines_joined = "".join(lines_joined)
        return all_lines_joined
