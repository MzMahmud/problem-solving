import java.util.*;

class Solution {
    public int nthUglyNumber(int n) {
        int i = 0, uglyNumber = 0;
        var uglyNumbers = new PriorityQueue<>(Comparator.<Integer>naturalOrder().reversed());
        uglyNumbers.add(1);
        while (i < n) {
            uglyNumber = uglyNumbers.poll();
            ++i;
            for (var factor : List.of(2, 3, 5)) {
                int next = factor * uglyNumber;
                if (!uglyNumbers.contains(next)) {
                    uglyNumbers.add(next);
                }
            }
        }
        return uglyNumber;
    }
}