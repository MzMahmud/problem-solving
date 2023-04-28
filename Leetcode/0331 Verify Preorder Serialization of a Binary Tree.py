class Solution:
    def isValidSerialization(self, preorder):
      n_nodes_in_stack, found_tree = 0, False
      for node in preorder.split(','):
        if found_tree: 
          return False
        if n_nodes_in_stack:
          n_nodes_in_stack -= 1
        if node != '#':
          n_nodes_in_stack += 2
        if n_nodes_in_stack == 0:
          found_tree = True
      return n_nodes_in_stack == 0
