class Solution {
    public boolean detectCapitalUse(String s) {
        if (s.length() < 2) return true;

        Predicate<Integer> expectedCaseChecker =
                Character.isUpperCase(s.charAt(0)) && Character.isUpperCase(s.charAt(1))
                ? Character::isUpperCase
                : Character::isLowerCase;

        return s.chars()
                .skip(1)
                .boxed()
                .allMatch(expectedCaseChecker);
    }
}