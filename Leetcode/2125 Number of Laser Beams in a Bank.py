class Solution:
    def numberOfBeams(self, bank):
        last_non_zero_lasers = 0
        n_beams = 0
        for row in bank:
            lasers = sum(map(int, row))
            if lasers != 0:
                n_beams += lasers * last_non_zero_lasers
                last_non_zero_lasers = lasers
        return n_beams
