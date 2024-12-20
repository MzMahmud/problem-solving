public class Solution
{
    public int SmallestNumber(int n)
    {
        int nBits = (int)Math.Log2(n);
        int bits = 1;
        for (int i = 0; i < nBits; i++)
        {
            bits <<= 1;
            bits |= 1;
        }
        return bits;
    }
}
