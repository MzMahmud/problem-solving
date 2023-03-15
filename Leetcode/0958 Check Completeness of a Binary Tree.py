class Solution:
    def isCompleteTree(self, root):
        queue = deque([root])
        none_node_found = False
        while queue:
            node = queue.popleft()
            if node is None:
                none_node_found = True
            else:                    
                if none_node_found:
                    return False
                queue.append(node.left)
                queue.append(node.right)
        return True
