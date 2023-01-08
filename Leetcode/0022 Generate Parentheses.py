class Solution:
    def generateParenthesis(self, N: int) -> List[str]:
        all_parenthesis = [[] for _ in range(N+1)]
        all_parenthesis[0] = ['']
        for n in range(1,N+1):
            for k in range(n):
                inside = all_parenthesis[k]
                right  = all_parenthesis[n-1-k]
                for i in inside:
                    for r in right:
                        all_parenthesis[n].append(f"({i}){r}")
        return all_parenthesis[N]
        