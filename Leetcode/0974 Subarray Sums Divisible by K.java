public class Solution {
    // O(n + k) time | O(k) space
    // the array version is easier to code
    // the hash map version is slightly more efficient, as it uses only the remainders the sub-arrays has
    public int subarraysDivByK(int[] numbers, int k) {
        int prefixSumModK = 0, answer = 0;

        int[] nPrefixSumsByRemainder = new int[k];
        // Map<Integer, Integer> nPrefixSumsByRemainder = new HashMap<>(k);

        for (int number : numbers) {
            prefixSumModK = (prefixSumModK + number % k + k) % k;

            answer += nPrefixSumsByRemainder[prefixSumModK];
            // answer += nPrefixSumsByRemainder.getOrDefault(prefixSumModK, 0);

            boolean isCurPrefixIsDivisible = prefixSumModK == 0;
            if (isCurPrefixIsDivisible) ++answer;

            ++nPrefixSumsByRemainder[prefixSumModK];
            // nPrefixSumsByRemainder.merge(prefixSumModK, 1 , Integer::sum);
        }
        return answer;
    }
}
