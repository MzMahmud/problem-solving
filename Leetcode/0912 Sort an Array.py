class Solution:
    def sortArray(self, a):
        merge_sort(a, 0, len(a) - 1, list(a))
        return a


def merge_sort(a, start, end, merged):
    n = end - start + 1
    if n < 2:
        return

    mid = start + (end - start) // 2
    merge_sort(a, start, mid, merged)
    merge_sort(a, mid + 1, end, merged)
    merge(a, start, mid, end, merged)


def merge(a, start, mid, end, merged):
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
    for m_i in range(k):
        a[i] = merged[m_i]
        i += 1