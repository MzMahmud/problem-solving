
def partition(n):
    """
    returns the number of partition of n
    """
    # consider the problem like a coin change
    # with coins ranges in 1 to n
    ways = [0 for i in range(n + 2)]
    # base case
    ways[0] = 1
    for i in range(1, n + 1):
        for num in range(i, n + 1):
            ways[num] += ways[num - i]
            # ways[num - i] because i-th coin in i
    return ways[n]


'''
partition(n) = # ways n can be written as sum of positive integers
partition(5) = 7, Because 
5 = 5 
  = 4 + 1 
  = 3 + 2
  = 3 + 1 + 1
  = 2 + 2 + 1
  = 2 + 1 + 1 + 1
  = 1 + 1 + 1 + 1 + 1
'''

# partition(100) - 1 because of at least two integer sum
# So 100 itself dont count
print(partition(100) - 1)
# 190569291
