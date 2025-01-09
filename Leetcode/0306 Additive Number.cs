public class Solution
{
    public bool IsAdditiveNumber(string s)
    {
        bool possible(int start, string a, string b, bool matched)
        {
            if (start >= s.Length) return matched;
            int maxLen = s[start] == '0' ? 1 : s.Length - start;
            for (int len = 1; len <= maxLen; len++)
            {
                string curr = s.Substring(start, len);
                bool yes = false;
                if (a != "" && b != "")
                {
                    string sum = Sum(a, b);
                    if (curr == sum)
                    {
                        yes |= possible(start + len, b, curr, true);
                    }
                    else
                    {
                        continue;
                    }
                }
                else if (a == "")
                {
                    yes |= possible(start + len, curr, b, false);
                }
                else
                {
                    yes |= possible(start + len, a, curr, false);
                }
                if (yes) return true;
            }
            return false;
        }
        return possible(0, "", "", false);
    }

    public static string Sum(string a, string b)
    {
        List<char> digits = [];
        int carry = 0;
        for (int i = a.Length - 1, j = b.Length - 1; i >= 0 || j >= 0; i--, j--)
        {
            int sum = carry;
            if (i >= 0) sum += a[i] - '0';
            if (j >= 0) sum += b[j] - '0';
            carry = sum / 10;
            sum %= 10;
            digits.Add((char)('0' + sum));
        }
        if (carry != 0) digits.Add((char)('0' + carry));
        digits.Reverse();
        return new([.. digits]);
    }
}
