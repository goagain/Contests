public class Solution
{
    static char[] sb;
    public string Convert (string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int loop = numRows * 2 - 2;
        int sLength = s.Length;
        if (sb == null || sb.Length < sLength)
            sb = new char[sLength * 2];
        int index = 0;
        for (int step = 0; step < numRows; step++)
        {
            for (int i = 0; i * loop < sLength; i++)
            {
                int firstIndex = i * loop + step;
                int secondIndex = i * loop + (loop - step) % loop;

                if (firstIndex < sLength)
                    sb[index++] = s[firstIndex];

                if (secondIndex != firstIndex && secondIndex < sLength)
                {
                    sb[index++] = s[secondIndex];
                }
            }
        }
        return new string (sb, 0, sLength);
    }
}