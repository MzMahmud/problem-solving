class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        Character[] mapFromStoT = new Character[256];
        Character[] mapFromTtoS = new Character[256];
        for (int i = 0; i < s.length(); ++i) {
            char cS = s.charAt(i);
            char cT = t.charAt(i);
            if (mapFromStoT[cS] == null && mapFromTtoS[cT] == null) {
                mapFromStoT[cS] = cT;
                mapFromTtoS[cT] = cS;
            } else if (!(Objects.equals(mapFromStoT[cS], cT) && Objects.equals(mapFromTtoS[cT], cS))) {
                return false;
            }
        }
        return true;
    }
}
