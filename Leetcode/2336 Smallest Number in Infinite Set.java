class SmallestInfiniteSet {
    private final SortedSet<Integer> sortedSmallerNumbers;
    private int smallestNumber;

    public SmallestInfiniteSet() {
        sortedSmallerNumbers = new TreeSet<>();
        smallestNumber = 1;
    }
    
    public int popSmallest() {
        int smallest;
        if (sortedSmallerNumbers.isEmpty()) {
            smallest = smallestNumber++;
        } else {
            smallest = sortedSmallerNumbers.first();
            sortedSmallerNumbers.remove(smallest);
        }
        return smallest;
    }
    
    public void addBack(int num) {
        if (num >= smallestNumber || sortedSmallerNumbers.contains(num)) {
            return;
        }
        sortedSmallerNumbers.add(num);
    }
}
