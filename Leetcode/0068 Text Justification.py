class Solution:
    def fullJustify(self, words, max_width):
        lines = get_lines(words, max_width)
        justified_lines = []
        last_line_index = len(lines) - 1
        for i, line in enumerate(lines):
            justified_line = get_justified_line(
                line, max_width, i == last_line_index)
            justified_lines.append("".join(justified_line))

        return justified_lines


def get_lines(words, max_width):
    lines = []
    char_in_line = 0
    for word in words:
        word_len = len(word)
        if char_in_line == 0 or (char_in_line + 1 + word_len) > max_width:
            lines.append([])
            line = lines[-1]
            char_in_line = word_len
        else:
            char_in_line += (1 + word_len)
        line.append(word)
    return lines


def get_justified_line(line, max_width, is_last_line):
    chars = 0
    for word in line:
        chars += len(word)

    spaces = max_width - chars
    space_places = len(line) - 1
    is_juftify_left = space_places == 0 or is_last_line

    equal_spaces, extra_space = 1, 0
    if not is_juftify_left:
        equal_spaces = spaces // space_places
        extra_space = spaces % space_places

    justified_line = []
    for i in range(len(line) - 1):
        justified_line.append(line[i])
        space_count = equal_spaces + (1 if i < extra_space else 0)
        justified_line.append(' ' * space_count)
        spaces -= 1

    justified_line.append(line[-1])
    if is_juftify_left:
        justified_line.append(' ' * spaces)

    return justified_line