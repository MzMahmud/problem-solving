class Solution {
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> seenAtIndexByNumber = new HashMap<>();
        for (int i = 0; i < numbers.length; ++i) {
            int neededNumber = target - numbers[i];
            if(seenAtIndexByNumber.containsKey(neededNumber)) {
                return new int[]{seenAtIndexByNumber.get(neededNumber), i};
            }
            seenAtIndexByNumber.put(numbers[i], i);
        }
        return new int[]{};   
    }
}
