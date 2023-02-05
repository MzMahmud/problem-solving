class Solution:
    def permuteUnique(self, nums):
        size, options = len(nums), {}

        for num in nums:
            options[num] = options.get(num, 0) + 1

        return build_permutations([], options, size, [])


def build_permutations(permutation, options, size, permutations):
    if len(permutation) == size:
        permutations.append(list(permutation))
        return

    for option in options:
        if options[option] == 0:
            continue

        options[option] -= 1
        permutation.append(option)

        build_permutations(permutation, options, size, permutations)

        permutation.pop()
        options[option] += 1

    return permutations
