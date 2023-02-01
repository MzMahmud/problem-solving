import java.util.Collection;

class Solution {
    public int[] findMode(TreeNode root) {
        var occurrences = countOccurrences(root, new HashMap<>());
        int maxOccurrence = 0;
        List<Integer> maxOccurrenceValues = new ArrayList<>();
        for (var valueOccurrence : occurrences.entrySet()) {
            int value = valueOccurrence.getKey();
            int occurrence = valueOccurrence.getValue();
            if (occurrence >= maxOccurrence) {
                if (occurrence > maxOccurrence) {
                    maxOccurrence = occurrence;
                    maxOccurrenceValues.clear();
                }
                maxOccurrenceValues.add(value);
            }
        }
        int[] modes = new int[maxOccurrenceValues.size()];
        int i = 0;
        for (var maxOccurrenceValue : maxOccurrenceValues) {
            modes[i++] = maxOccurrenceValue;
        }
        return modes;
    }

    public Map<Integer, Integer> countOccurrences(TreeNode root, Map<Integer, Integer> counts) {
        if (root != null) {
            counts.compute(root.val, (k, v) -> (v == null ? 0 : v) + 1);
            countOccurrences(root.left, counts);
            countOccurrences(root.right, counts);
        }
        return counts;
    }
}