class Solution {
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        DisjointSet disjointSet = new DisjointSet();
        for (int i = 0; i < s1.length(); ++i) {
            disjointSet.merge(s1.charAt(i), s2.charAt(i));
        }
        StringBuilder equivalentString = new StringBuilder(baseStr);
        for (int i = 0; i < equivalentString.length(); ++i) {
            char equivalentChar = disjointSet.getParent(equivalentString.charAt(i));
            equivalentString.setCharAt(i, equivalentChar);
        }
        return equivalentString.toString();
    }

    private static class DisjointSet {
        private final int[] parents;

        public DisjointSet() {
            parents = new int[26];
            for (int i = 0; i < parents.length; ++i) {
                parents[i] = i;
            }
        }

        public void merge(char a, char b) {
            int charIndexA = a - 'a';
            int charIndexB = b - 'a';
            int minParentCharIndex = Math.min(
                    getParentIndex(charIndexA),
                    getParentIndex(charIndexB)
            );
            setParent(charIndexA, minParentCharIndex);
            setParent(charIndexB, minParentCharIndex);
        }

        public char getParent(char ch) {
            return (char) ('a' + getParentIndex(ch - 'a'));
        }

        private int getParentIndex(int charIndex) {
            if (charIndex == parents[charIndex]) {
                return charIndex;
            }
            return parents[charIndex] = getParentIndex(parents[charIndex]);
        }

        private int setParent(int charIndex, int parent) {
            if (parents[charIndex] == charIndex) {
                return parents[charIndex] = parent;
            }
            return parents[charIndex] = setParent(parents[charIndex], parent);
        }
    }
}
