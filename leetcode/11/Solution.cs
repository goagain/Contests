using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
public class Solution
{
    int[] height;
    public int MaxArea(int[] height)
    {
        this.height = height;
        List<int> extremumList = new List<int>();
        List<int> right = new List<int>();
        int ans = 0;
        for (int i = 0; i < height.Length; i++)
        {
            if (extremumList.Count == 0 || height[extremumList[extremumList.Count - 1]] < height[i])
            {
                extremumList.Add(i);
                right.Add(i);
            }


            int index = BinarySearch(extremumList, height[i]);

            if (ans < (i - extremumList[index]) * height[i])
            {
                ans = (i - extremumList[index]) * height[i];
            }
            if (index >= 1)
            {
                right[index - 1] = i;
            }
            if (height[extremumList[index]] < height[i] || index > 1 && height[extremumList[index-1]] > height[i])
            {
                throw new Exception();
            }
            if (height[i] == height[extremumList[index]])
                right[index] = i;

        }

        int mostRight = 0;
        for (int i = extremumList.Count - 1; i >= 0; i--)
        {
            if (right[i] > mostRight)
                mostRight = right[i];
            if (ans < height[extremumList[i]] * (mostRight - extremumList[i]))
            {
                ans = height[extremumList[i]] * (mostRight - extremumList[i]);
            }
        }
        return ans;
    }
    
    int BinarySearch(List<int> sortedList, int wanted)
    {
        //for (int i = 0; i < sortedList.Count; i++)
        //{
        //    if (height[sortedList[i]] >= wanted)
        //        return i;
        //}
        //throw new Exception();
        int l = 0;
        int r = sortedList.Count - 1;

        while (l < r)
        {
            int m = (l + r) / 2;
            if (height[sortedList[m]] < wanted)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        //if (l == 0 && sortedList[l] < wanted)
        //    return -1;
        return l;
    }

    public static void Main(string[] args)
    {
        //int[] list = new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        //int[] list = new int[] { 1, 2, 1 };
        int[] list = new int[] {184, 34, 97, 143, 84, 199, 59, 64, 130, 159, 67, 12, 91, 89, 134, 14, 114, 137, 111, 44, 90, 109, 174, 81, 92, 63, 80, 94, 62, 44, 141, 199, 78, 190, 142, 162, 189, 1, 26, 120, 113, 45, 84, 156, 86, 171, 171, 1, 108, 34, 197, 199, 143, 124, 32, 35, 187, 113, 81, 2, 157, 22, 1, 187, 165, 95, 149, 154, 97, 128, 26, 162, 125, 63, 118, 12, 34, 89, 165, 142, 124, 114, 93, 19, 38, 126, 7, 178, 191, 88, 132, 100, 63, 85, 87, 180, 180, 188, 134, 29};
        Solution solution = new Solution();
        Console.Out.WriteLine(solution.MaxArea(list));
        Console.In.Read();
    }
}