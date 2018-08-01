public class Solution
{
    public int LengthOfLongestSubstring (string s)
    {
        int maxLength = 0;
        int maxStart = 0, maxEnd = 0;
        int start = 0, end = 0;
        bool[] set = new bool[256];
        for (int i = 0; i < s.Length; i++)
        {
            if (set[s[i]])
            {
                while (s[start] != s[i])
                {
                    set[s[start]] = false;
                    start++;
                }
                start++;
            }
            else
            {
                end = i;
                set[s[i]] = true;
                if (end - start + 1 > maxLength)
                {
                    maxLength = end - start + 1;
                    maxStart = start;
                    maxEnd = end;
                }
            }
        }
        return maxLength;
    }
}