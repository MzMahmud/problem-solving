class Solution:
    def simplifyPath(self, path) -> str:
      stack = []
      for dir in path.split("/"):
        if dir == '..' and stack:
          stack.pop()
        elif dir not in ['', '.', '..']:
          stack.append(dir)
      return f'/{"/".join(stack)}'
    
