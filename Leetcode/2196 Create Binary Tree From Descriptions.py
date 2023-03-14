class Solution:
    def createBinaryTree(self, descriptions):
        parents = {}
        tree_nodes = {}
        
        for parent, child, is_left in descriptions:
            if parent not in tree_nodes:
                tree_nodes[parent] = TreeNode(parent)
            if child not in tree_nodes:
                tree_nodes[child] = TreeNode(child)
            
            if is_left:
                tree_nodes[parent].left = tree_nodes[child]
            else:
                tree_nodes[parent].right = tree_nodes[child]
            
            parents[child] = parent
        
        for node in tree_nodes:
            if node not in parents:
                return tree_nodes[node]
        
        return None
