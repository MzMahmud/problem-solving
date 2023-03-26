class Solution:
    def longestCycle(self, edges):
        n, time = len(edges), 1
        longest_cycle_len = -1
        visit_time = [0] * len(edges)

        for node in range(n):
            if visit_time[node] > 0:
                continue

            start_time = time
            
            while node != -1 and visit_time[node] == 0:
                visit_time[node] = time
                time += 1
                node = edges[node]

            if node != -1 and visit_time[node] >= start_time:
                longest_cycle_len = max(longest_cycle_len, time - visit_time[node])
        
        return longest_cycle_len
