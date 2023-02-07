import java.util.*;

class Solution {
    private static final int BASKET_SIZE = 2;

    public int totalFruit(int[] fruits) {
        int left = 0, maxWindowSize = 0;
        Map<Integer, Integer> lastSeenIndex = new HashMap<>();

        for (int right = 0; right < fruits.length; ++right) {
            int fruit = fruits[right];

            if (!lastSeenIndex.containsKey(fruit) && lastSeenIndex.size() == BASKET_SIZE) {
                int minIndex = Integer.MAX_VALUE, minIndexFruit = 0;
                for (var fruitIndex : lastSeenIndex.entrySet()) {
                    int index = fruitIndex.getValue();
                    if (index < minIndex) {
                        minIndex = index;
                        minIndexFruit = fruitIndex.getKey();
                    }
                }
                left = minIndex + 1;
                lastSeenIndex.remove(minIndexFruit);
            }
            
            lastSeenIndex.put(fruit, right);
            int windowSize = right - left + 1;
            maxWindowSize = Math.max(maxWindowSize, windowSize);
        }
        return maxWindowSize;
    }
}