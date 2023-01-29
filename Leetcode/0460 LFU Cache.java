class LFUCache {
    private final int capacity;
    private final Map<Integer, ValueFrequency> valueFrequencyByKey;
    private int minimumFrequency;
    private final Map<Integer, Set<Integer>> keysByFrequency;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.valueFrequencyByKey = new HashMap<>();
        this.minimumFrequency = 0;
        this.keysByFrequency = new HashMap<>();
    }

    public int get(int key) {
        var valueFrequency = valueFrequencyByKey.get(key);
        if (valueFrequency == null) {
            return -1;
        }
        var keysOfItemFreq = keysByFrequency.get(valueFrequency.frequency);
        keysOfItemFreq.remove(key);
        if (minimumFrequency == valueFrequency.frequency && keysOfItemFreq.isEmpty()) {
            ++minimumFrequency;
        }
        ++valueFrequency.frequency;
        keysByFrequency.computeIfAbsent(valueFrequency.frequency, k -> new LinkedHashSet<>()).add(key);
        return valueFrequency.value;
    }


    public void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        var valueFrequency = valueFrequencyByKey.get(key);
        if (valueFrequency != null) {
            valueFrequency.value = value;
            get(key);
            return;
        }
        if (valueFrequencyByKey.size() == capacity) {
            var keysOfMinFreq = keysByFrequency.get(minimumFrequency);
            var keyToRemove = keysOfMinFreq.iterator().next();
            keysOfMinFreq.remove(keyToRemove);
            valueFrequencyByKey.remove(keyToRemove);
        }
        minimumFrequency = 1;
        valueFrequencyByKey.put(key, new ValueFrequency(value, minimumFrequency));
        keysByFrequency.computeIfAbsent(minimumFrequency, k -> new LinkedHashSet<>()).add(key);
    }

    private static class ValueFrequency {
        int value;
        int frequency;

        ValueFrequency(int value, int frequency) {
            this.value = value;
            this.frequency = frequency;
        }
    }
}