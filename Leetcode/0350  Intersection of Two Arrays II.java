class Solution {
    // O(n + m) time | O(min(n,m)) space
    public int[] intersect(int[] nums1, int[] nums2) {
        if(nums1.length < nums2.length) {
            return intersect(nums2, nums1);
        }
        // min(n, m) space
        var occuranceInNums1 = 
            Arrays.stream(nums1)
                  .boxed()
                  .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        List<Integer> intersectList = new ArrayList<>();
        for(var num : nums2) {
            var occurance = occuranceInNums1.getOrDefault(num, 0L);
            if(occurance > 0) {
                intersectList.add(num);
                occuranceInNums1.put(num, occurance - 1);
            }
        }
        return intersectList.stream().mapToInt(n -> n).toArray();
    }

    // O(n log n + m log m) time | O(1) extra space
    // if the arrays are already sorted O(n + m) time
    public int[] _intersect(int[] nums1, int[] nums2) {
        // n log n time
        Arrays.sort(nums1);
        // m log m time
        Arrays.sort(nums2);

        List<Integer> intersectList = new ArrayList<>();
        // n + m time
        for(int i = 0, j = 0; i < nums1.length && j < nums2.length; ) {
            if(nums1[i] < nums2[j]) {
                ++i;
            } else if(nums1[i] > nums2[j]) {
                ++j;
            } else {
                intersectList.add(nums1[i]);
                ++i;
                ++j;
            }
        }
        return intersectList.stream().mapToInt(n -> n).toArray();
    }
}
