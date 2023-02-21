class Solution:
    def singleNonDuplicate(self, a):
        lo, hi = 0, len(a) - 1
        mid = lo + (hi - lo) // 2
        while lo < hi:
            if a[mid-1] != a[mid] != a[mid+1]:
                break

            if a[mid-1] == a[mid]:
                left = (lo, mid)
                right = (mid + 1, hi)
            else:
                left = (lo, mid-1)
                right = (mid, hi)

            lo, hi = left if is_odd_sized(left) else right
            mid = lo + (hi - lo) // 2

        return a[mid]


def is_odd_sized(interval):
    return (interval[1] - interval[0] + 1) % 2 == 1
