class Solution:
    def finalValueAfterOperations(self, operations):
        return sum(map(operate, operations))


def operate(operation):
    return 1 if operation in ["++X", "X++"] else -1
