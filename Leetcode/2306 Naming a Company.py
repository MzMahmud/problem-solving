class Solution:
    def distinctNames(self, ideas):
        suffixes_by_start = {}
        start_chars_by_suffix = {}
        for idea in ideas:
            start = idea[0]
            suffix = idea[1:]

            if start not in suffixes_by_start:
                suffixes_by_start[start] = set()
            suffixes_by_start[start].add(suffix)

            if suffix not in start_chars_by_suffix:
                start_chars_by_suffix[suffix] = set()
            start_chars_by_suffix[suffix].add(start)

        n_suffixes_start_char_not_start_char = {
            start: {other_start: 0 for other_start in suffixes_by_start}
            for start in suffixes_by_start
        }
        starts = set(suffixes_by_start.keys())
        for start, suffixes in suffixes_by_start.items():
            for suffix in suffixes:
                for other_start in starts.difference(start_chars_by_suffix[suffix]):
                    n_suffixes_start_char_not_start_char[start][other_start] += 1

        names = 0
        for idea in ideas:
            suffix = idea[1:]
            start = idea[0]
            for other_start in starts.difference(start_chars_by_suffix[suffix]):
                names += n_suffixes_start_char_not_start_char[other_start][start]

        return names
