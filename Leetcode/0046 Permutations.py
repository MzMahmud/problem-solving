class Solution:
    def permute(self, array):
        return self.build_permutation_inplace(array, 0, [])
        # return self.build_permutation([], set(array), [])

    # inplace swap O(1) space
    def build_permutation_inplace(self, array, i, permutations):
        n = len(array)
        if i == n:
            permutations.append(list(array))
            return
        for j in range(i, n):
            self.swap(i, j, array)
            self.build_permutation(array, i + 1, permutations)
            self.swap(i, j, array)
        return permutations

    def swap(self, i, j, array):
        array[i], array[j] = array[j], array[i]

    # build recurrsively with options tracking O(n) space
    def build_permutation(self, permutation, options, permutations):
        if not options:
            permutations.append(list(permutation))
            return

        for option in set(options):
            permutation.append(option)
            options.remove(option)
            self.build_permutation(permutation, options, permutations)
            options.add(option)
            permutation.pop()

        return permutations
