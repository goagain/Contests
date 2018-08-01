public class Solution
{
    bool isValidIndex (int[] array, int index)
    {
        if (index >= 0 && index < array.Length)
            return true;
        return false;
    }
    public double FindMedianSortedArrays (int[] nums1, int[] nums2)
    {
        int totalLength = nums1.Length + nums2.Length;
        int[] a, b;
        if (nums1.Length > nums2.Length)
        {
            a = nums1;
            b = nums2;
        }
        else
        {
            b = nums1;
            a = nums2;
        }

        int l = 0, r = a.Length;
        while (l < r)
        {
            int m = (l + r) / 2;
            int aSelect = m;
            int bSelect = totalLength / 2 - aSelect;
            int aIndex = aSelect - 1;
            int bIndex = bSelect - 1;
            if (bSelect < 0)
            {
                r = m;
            }
            else if (bSelect > b.Length)
            {
                l = m + 1;
            }
            else
            {
                if (
                    (isValidIndex (a, aIndex + 1) && isValidIndex (b, bIndex) && a[aIndex + 1] < b[bIndex])
                )
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
        }
        Console.Out.WriteLine ("----" + l);

        if (totalLength % 2 == 1)
        {
            int aIndex = l - 1;
            int bIndex = totalLength / 2 - l - 1;

            int result = int.MaxValue;
            if (isValidIndex (a, aIndex + 1))
                result = Math.Min (result, a[aIndex + 1]);
            if (isValidIndex (b, bIndex + 1))
                result = Math.Min (result, b[bIndex + 1]);
            return result;
        }
        else
        {
            int aIndex = l - 1;
            int bIndex = totalLength / 2 - l - 1;

            int lm = int.MinValue;
            if (isValidIndex (a, aIndex))
                lm = Math.Max (lm, a[aIndex]);
            if (isValidIndex (b, bIndex))
                lm = Math.Max (lm, b[bIndex]);

            int rm = int.MaxValue;
            if (isValidIndex (a, aIndex + 1))
                rm = Math.Min (rm, a[aIndex + 1]);
            if (isValidIndex (b, bIndex + 1))
                rm = Math.Min (rm, b[bIndex + 1]);
            return (lm + rm) / 2.0;
        }
    }
}