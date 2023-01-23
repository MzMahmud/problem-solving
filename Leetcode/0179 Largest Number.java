class Solution {
    public String largestNumber(int[] nums) {
        String[] numStrings = new String[nums.length];
        for (int i = 0; i < numStrings.length; ++i) {
            numStrings[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(numStrings, this::compare);
        if ("0".equals(numStrings[0])) {
            return "0";
        }
        return String.join("", numStrings);
    }

    private int compare(String a, String b) {
        String ba = b.concat(a);
        String ab = a.concat(b);
        return ba.compareTo(ab);
    }
}
