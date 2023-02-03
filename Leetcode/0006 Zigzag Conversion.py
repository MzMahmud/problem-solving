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

    """
    O(n) time, O(1) extra space (O(n) sapce is needed to return result)
    
    0     8         16
    1   7 9      15 17
    2  6  10   14   18
    3 5   11 13     19
    4     12        20
    
    notice that 1st and last row has indces in increment = 2 * (n_rows - 1)
    0 8  16...
    4 12 20...
    the other rows additionally has next increment - 2 * row index
    1   9   17 normal increment
      7   15   additional values
      
    2   10   18 normal increment
      6    14   additional values
    """  
    def convert(self, string, n_rows):
        n = len(string)
        if n_rows == 1 or n_rows >= n:
            return string
        
        converted = []
        last_row = n_rows - 1
        first_last_row = (0, last_row)
        
        for row in range(n_rows):
            increment = 2 * (n_rows - 1)
            for char_index in range(row, n, increment):
                converted.append(string[char_index])
                
                if row in first_last_row:
                    continue
                
                extra_char_index = char_index + increment - 2 * row
                if 0 <= extra_char_index < n:
                    converted.append(string[extra_char_index])
        
        return "".join(converted)
