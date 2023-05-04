class Solution:
    def predictPartyVictory(self, senate):
        queue = deque()
        r_count, d_count = 0, 0
        for s in senate:
            queue.append(s)
            if s == 'R': 
                r_count += 1
            else: 
                d_count += 1
        r_ban_count, d_ban_count = 0, 0
        while r_count and d_count:
            s = queue.popleft()
            if s == 'R':
                if r_ban_count:
                    r_ban_count -= 1
                    r_count -= 1
                else:
                    d_ban_count += 1
                    queue.append(s)
            else:
                if d_ban_count:
                    d_ban_count -= 1
                    d_count -= 1
                else:
                    r_ban_count += 1
                    queue.append(s)
        return "Radiant" if d_count == 0 else "Dire"
