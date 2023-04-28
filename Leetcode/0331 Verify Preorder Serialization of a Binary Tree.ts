function isValidSerialization(preorder: string): boolean {
  let nNodesInStack = 0, foundTree = false;
  for (const node of preorder.split(',')) {
    if (foundTree) {
      return false;
    }
    if (nNodesInStack) {
      nNodesInStack--;
    }
    if (node !== '#') {
      nNodesInStack += 2
    }
    if (nNodesInStack === 0) {
      foundTree = true;
    }
  }
  return nNodesInStack === 0;
}
