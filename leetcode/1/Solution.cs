using System.Collections;
using System.Collections.Generic;

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> map = new Dictionary<int, int>();
        for(int i = 0; i < nums.Length; i++)
        {
            int value = nums[i];
            int diff = target - value;
            if (map.ContainsKey(diff))
            {
                return new int[] {map[diff], i};
            }
            if (!map.ContainsKey(value))
                map.Add(value, i);
        }
        return null;
    }
}