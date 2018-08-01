public class Solution {
    public string LongestPalindrome(string s)
    {
        int maxLength = 0, maxL = 0, maxR = 0;

        for(int center = 0; center < s.Length; center++)
        {
            for(int length = 0; center - length >= 0 && center + length < s.Length; length++)
            {
                int l = center - length, r = center + length;
                if (s[l] == s[r])
                {
                    int tmpLength = length * 2 + 1;
                    if (tmpLength > maxLength)
                    {
                        maxL = l;
                        maxR = r;
                        maxLength = tmpLength;
                    }
                }
                else
                    break;
            }
            for (int length = 0; center - length >= 0 && center + length + 1< s.Length; length++)
            {
                int l = center - length, r = center + length + 1;
                if (s[l] == s[r])
                {
                    int tmpLength = length * 2 + 2;
                    if (tmpLength > maxLength)
                    {
                        maxL = l;
                        maxR = r;
                        maxLength = tmpLength;
                    }
                }
                else
                    break;
            }
        }
        return s.Substring(maxL, maxLength);
    }
}