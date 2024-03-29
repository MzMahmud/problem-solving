class Solution {
    private static final BiFunction<Integer, Long, Long> reduceCountFunction = (n, countN) -> countN - 1;

    public int[] findOriginalArray(int[] changed) {
        if (changed.length % 2 == 1) {
            return new int[0];
        }
        Arrays.sort(changed);
        Map<Integer, Long> count = Arrays.stream(changed)
                                         .boxed()
                                         .collect(Collectors.groupingBy(
                                                 Function.identity(),
                                                 Collectors.counting()
                                         ));
        ArrayList<Integer> original = new ArrayList<>();
        for (int number : changed) {
            if (count.get(number) == 0) {
                continue;
            }
            int doubled = number << 1;
            if (count.getOrDefault(doubled, 0L) == 0) {
                return new int[0];
            }
            original.add(number);
            count.compute(number, reduceCountFunction);
            count.compute(doubled, reduceCountFunction);
        }
        return original.stream()
                       .mapToInt(integer -> integer)
                       .toArray();
    }
}
