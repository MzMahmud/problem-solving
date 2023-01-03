class Solution {
    public boolean isInSortedOrder(String[] strings, int columnIndex) {
        Character prev = null;
        for (String string : strings) {
            char curr = string.charAt(columnIndex);
            if (prev != null && prev > curr) {
                return false;
            }
            prev = curr;
        }
        return true;
    }

    public int minDeletionSize(String[] strings) {
        int stringSize = strings[0].length();
        return IntStream.range(0, stringSize)
                        .mapToObj(columnIndex -> isInSortedOrder(strings, columnIndex))
                        .mapToInt(isSorted -> isSorted ? 0 : 1)
                        .sum();
    }
}
