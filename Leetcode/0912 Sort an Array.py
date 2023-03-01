class Solution:
    def sortArray(self, a):
        merge_sort(a, 0, len(a) - 1)
        return a


def merge_sort(a, start, end):
    n = end - start + 1
    if n < 2:
        return

    mid = start + (end - start) // 2
    merge_sort(a, start, mid)
    merge_sort(a, mid + 1, end)
    merge(a, start, mid, end)


def merge(a, start, mid, end):
    merged = [0] * (end - start + 1)
    i, j, k = start, mid + 1, 0
    while i <= mid and j <= end:
        if a[j] < a[i]:
            merged[k] = a[j]
            j += 1
        else:
            merged[k] = a[i]
            i += 1
        k += 1

    while i <= mid:
        merged[k] = a[i]
        i += 1
        k += 1

    while j <= end:
        merged[k] = a[j]
        j += 1
        k += 1

    i = start
    for v in merged:
        a[i] = v
        i += 1
