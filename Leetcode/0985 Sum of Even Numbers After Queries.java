class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        int sumOfEvenNumbers = Arrays.stream(nums)
                                     .filter(n -> n % 2 == 0)
                                     .sum();
        int[] answer = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            int index = queries[i][1];
            if (nums[index] % 2 == 0) {
                sumOfEvenNumbers -= nums[index];
            }
            nums[index] += queries[i][0];
            if (nums[index] % 2 == 0) {
                sumOfEvenNumbers += nums[index];
            }
            answer[i] = sumOfEvenNumbers;
        }
        return answer;
    }
}