public class RandomizedCollection {
    private final List<Integer> values;
    private final Map<Integer, Set<Integer>> valueToIndices;
    private final Random random;

    public RandomizedCollection() {
        values = new ArrayList<>();
        valueToIndices = new HashMap<>();
        random = new Random();
    }

    public boolean insert(int value) {
        boolean isPresent = valueToIndices.containsKey(value) 
                            && valueToIndices.get(value).size() > 0;
        values.add(value);
        valueToIndices.computeIfAbsent(value, k -> new LinkedHashSet<>()).add(values.size() - 1);
        return !isPresent;
    }

    private int getFirstIndex(int value) {
        return valueToIndices
                .get(value)
                .iterator()
                .next();
    }

    public boolean remove(int value) {
        boolean isPresent = valueToIndices.containsKey(value) 
                            && valueToIndices.get(value).size() > 0;
        if (!isPresent) {
            return false;
        }
        int index = getFirstIndex(value);
        int lastIndex = values.size() - 1;
        int lastIndexValue = values.get(lastIndex);

        valueToIndices.get(value).remove(index);
        values.set(index, lastIndexValue);
        valueToIndices.get(lastIndexValue).add(index);
        valueToIndices.get(lastIndexValue).remove(lastIndex);
        values.remove(lastIndex);
        return true;
    }

    public int getRandom() {
        int randomIndex = random.nextInt(values.size());
        return values.get(randomIndex);
    }
}
