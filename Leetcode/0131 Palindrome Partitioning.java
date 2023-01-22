class Solution {
    private List<List<String>> allPalinromes;
    public List<List<String>> partition(String s) {
        allPalinromes = new ArrayList<>();
        populateAllPalindromes(0, s, new ArrayList<>());
        return allPalinromes;
    }

    private void populateAllPalindromes(int start, String s, List<String> currentPartition) {
        if(start >= s.length()) {
            allPalinromes.add(new ArrayList<>(currentPartition));
            return;
        }
        for(int end = start; end < s.length(); ++end) {
            if(isPalindome(s, start, end)) {
                currentPartition.add(s.substring(start, end + 1));
                populateAllPalindromes(end + 1, s, currentPartition);
                currentPartition.remove(currentPartition.size() - 1);
            }
        }
    }

    private boolean isPalindome(String s, int start, int end) {
        while(start < end) {
            if(s.charAt(start) != s.charAt(end)) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
}
