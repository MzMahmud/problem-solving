class Solution:
    def validateStackSequences(self, pushed, popped):
        pushing = []
        popped_top = 0
        for val in pushed:
            pushing.append(val)
            while (
                len(pushing) != 0
                and popped_top < len(popped)
                and pushing[-1] == popped[popped_top]   
            ):
                pushing.pop()
                popped_top += 1
        
        return len(pushing) == 0 and popped_top == len(popped)
