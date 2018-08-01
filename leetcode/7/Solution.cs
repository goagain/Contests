public class Solution
{
    public int Reverse (int x)
    {
        try
        {
            checked
            {
                int ret = 0;
                int sign = x >= 0 ? 1 : -1;
                x = Math.Abs (x);
                while (x != 0)
                {
                    int mod = x % 10;
                    x /= 10;
                    ret *= 10;
                    ret += mod;
                }
                return ret * sign;
            }
        }
        catch
        {
            return 0;
        }
    }
}