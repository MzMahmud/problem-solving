class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        possible_judges = dict()
        for n in range(1, N + 1):
            possible_judges[n] = 0
        for ai, bi in trust:
            if ai in possible_judges:
                del possible_judges[ai]
            if bi in possible_judges:
                possible_judges[bi] += 1
        for possible_judge, trust_count in possible_judges.items():
            if trust_count == (N - 1):
                return possible_judge
        return -1
