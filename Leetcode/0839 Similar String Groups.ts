function numSimilarGroups(strs: string[]): number {
  const adjList = buildGraph(strs);
  const n = strs.length;
  const visited = new Array<boolean>(n).fill(false);
  function dfs(start: number) {
    if (visited[start]) {
      return;
    }
    visited[start] = true;
    for (const neighbour of adjList[start]) {
      dfs(neighbour);
    }
  }
  let nGroups = 0;
  for (let node = 0; node < n; node++) {
    if (!visited[node]) {
      dfs(node);
      nGroups++;
    }
  }
  return nGroups;
}

function buildGraph(strs: string[]) {
  const n = strs.length;
  const adjList = new Array<number[]>(n);
  for (let i = 0;i < n; i++) {
    adjList[i] = [];
  }
  for (let i = 0;i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      if (isSimilar(strs[i], strs[j])) {
        adjList[i].push(j);
        adjList[j].push(i);
      }
    }
  }
  return adjList;
}

function isSimilar(a: string, b: string): boolean {
  let diff = 0;
  for (let i = 0; i < a.length; i++) {
    if (a[i] !== b[i]) {
      diff++;
    }
  }
  return diff === 0 || diff == 2;
}
