public class Solution
{
    public bool IsMatch (string s, string p)
    {
        System.Text.RegularExpressions.Regex regex = new System.Text.RegularExpressions.Regex ("^" + p + "$");
        return regex.IsMatch (s);
    }
}