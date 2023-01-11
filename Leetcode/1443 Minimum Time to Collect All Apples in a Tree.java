import java.util.Collection;

class Solution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        Map<Integer, List<Integer>> childrenByNode = new HashMap<>();
        for (var edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if (!childrenByNode.containsKey(a)) {
                childrenByNode.put(a, new ArrayList<>());
            }
            if (!childrenByNode.containsKey(b)) {
                childrenByNode.put(b, new ArrayList<>());
            }
            childrenByNode.get(a).add(b);
            childrenByNode.get(b).add(a);
        }
        Integer timeToGetApple = minTimeToGetApple(0, -1, childrenByNode, hasApple);
        return timeToGetApple == null ? 0 : timeToGetApple;
    }

    private Integer minTimeToGetApple(int root, int parent, Map<Integer, List<Integer>> childrenByNode, List<Boolean> hasApple) {
        Integer time = hasApple.get(root) ? 0 : null;
        for (int child : childrenByNode.getOrDefault(root, List.of())) {
            if (child == parent) {
                continue;
            }
            Integer minTimeOfChild = minTimeToGetApple(child, root, childrenByNode, hasApple);
            if (minTimeOfChild != null) {
                time = (time == null ? 0 : time) + minTimeOfChild + 2;
            }
        }
        return time;
    }
}

class FunctionalSolution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        Map<Integer, List<Integer>> childrenByNode =
                Arrays.stream(edges)
                      .map(FunctionalSolution::getBidirectionalEdges)
                      .flatMap(Collection::stream)
                      .collect(Collectors.groupingBy(
                              FunctionalSolution::getFromNodeIndex,
                              Collectors.mapping(FunctionalSolution::getToNodeIndex, Collectors.toList())
                      ));
        Integer timeToGetApple = minTimeToGetApple(0, -1, childrenByNode, hasApple);
        return timeToGetApple == null ? 0 : timeToGetApple;
    }

    private Integer minTimeToGetApple(int root, int parent, Map<Integer, List<Integer>> childrenByNode, List<Boolean> hasApple) {
        int childMinTime =
                childrenByNode.getOrDefault(root, List.of())
                              .stream()
                              .filter(child -> child != parent)
                              .map(child -> minTimeToGetApple(child, root, childrenByNode, hasApple))
                              .filter(Objects::nonNull)
                              .mapToInt(minTime -> minTime + 2)
                              .sum();
        boolean hasAnyApples = hasApple.get(root) || childMinTime > 0;
        return hasAnyApples ? childMinTime : null;
    }

    private static Integer getFromNodeIndex(int[] edge) {
        return edge[0];
    }

    private static Integer getToNodeIndex(int[] edge) {
        return edge[1];
    }

    private static List<int[]> getBidirectionalEdges(int[] edge) {
        return List.of(edge, new int[]{edge[1], edge[0]});
    }
}
