class RandomizedSet {
    private final List<Integer> values;
    private final Map<Integer, Integer> valueToIndex;
    private final Random random;

    public RandomizedSet() {
        values = new ArrayList<>();
        valueToIndex = new HashMap<>();
        random = new Random();
    }

    public boolean insert(int value) {
        if (valueToIndex.containsKey(value)) {
            return false;
        }
        values.add(value);
        valueToIndex.put(value, values.size() - 1);
        return true;
    }

    private void swapWithEnd(int index) {
        int indexValue = values.get(index);
        int lastIndex = values.size() - 1;
        int lastIndexValue = values.get(lastIndex);
        values.set(index, lastIndexValue);
        valueToIndex.put(lastIndexValue, index);
        values.set(lastIndex, indexValue);
        valueToIndex.put(indexValue, lastIndex);
    }

    public boolean remove(int value) {
        if (!valueToIndex.containsKey(value)) {
            return false;
        }
        swapWithEnd(valueToIndex.get(value));
        values.remove(values.size() - 1);
        valueToIndex.remove(value);
        return true;
    }

    public int getRandom() {
        int randomIndex = random.nextInt(values.size());
        return values.get(randomIndex);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
