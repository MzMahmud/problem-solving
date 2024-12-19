public class Solution
{
    public bool AreOccurrencesEqual(string s)
    {
        var countOfChar = new int[26];
        int anyCount = 0;
        foreach (char ch in s)
        {
            int index = ch - 'a';
            anyCount = ++countOfChar[index];
        }
        return countOfChar.All(count => count == 0 || count == anyCount);
    }
}
