class Solution:
    def minimumTime(self, times, total_trips):
        min_time = min(times)
        lo, hi = min_time, total_trips * lo
        time = 0
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if can_make_trips(mid, times, total_trips):
                time = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return time


def can_make_trips(time, times, total_trips):
    trips = sum(map(lambda t: time // t, times))
    return trips >= total_trips
