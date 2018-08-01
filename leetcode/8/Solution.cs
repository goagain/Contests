public class Solution
{
    public int MyAtoi (string str)
    {
        str = str.TrimStart ();
        int sign = 1;
        if (string.IsNullOrEmpty (str))
            return 0;
        try
        {
            checked
            {
                int index = 0;
                int ret = 0;
                if (str[0] == '+')
                {
                    sign = 1;
                    index++;
                }
                else if (str[0] == '-')
                {
                    sign = -1;
                    index++;
                }
                if (index >= str.Length || !char.IsDigit (str[index]))
                {
                    return 0;
                }
                for (; index < str.Length; index++)
                {
                    if (!char.IsDigit (str[index]))
                        break;
                    ret = ret * 10 + (str[index] - '0');
                }
                return ret * sign;
            }
        }
        catch
        {
            if (sign == 1)
                return int.MaxValue;
            else
                return int.MinValue;
        }
    }
}