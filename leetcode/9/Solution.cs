public class Solution
{
    public bool IsPalindrome (int x)
    {
        if (x < 0)
            return false;
        string s = x.ToString ();
        for (int i = 0; i < s.Length; i++)
        {
            int j = s.Length - i - 1;
            if (i > j)
                return true;
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
}