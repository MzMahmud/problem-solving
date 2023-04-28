function isValidSerialization(preorder: string): boolean {
  let i = 0, nNodesInStack = 0, foundTree = false;
  while (i < preorder.length) {
    if (foundTree) {
      return false;
    }
    let node = '';
    while (i < preorder.length && preorder[i] !== ',') {
      node += preorder[i++];
    }
    i++;
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
  return nNodesInStack == 0;
}
