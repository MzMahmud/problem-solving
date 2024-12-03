class Solution {
    public String addSpaces(String s, int[] spaces) {
        var chars = new char[s.length() + spaces.length];
        for (int i = 0, j = 0, k = 0; i < s.length(); i++) {
            if (j < spaces.length && i == spaces[j]) {
                j++;
                chars[k++] = ' ';
            }
            chars[k++] = s.charAt(i);
        }
        return new String(chars);
    }
  
    public String addSpaces(String s, int[] spaces) {
        var newString = new StringBuilder(s.length() + spaces.length);
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (j < spaces.length && i == spaces[j]) {
                j++;
                newString.append(' ');
            }
            newString.append(s.charAt(i));
        }
        return newString.toString();
    }
}
