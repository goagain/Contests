using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq;

public class Solution
{
    public string[] UncommonFromSentences(string A, string B)
    {
        string[] arrA = A.Split(' ');
        string[] arrB = B.Split(' ');
        Dictionary<string, int> map = new Dictionary<string, int>();
        List<string> ans = new List<string>();
        foreach (string mem_a in arrA)
        {
            if (map.ContainsKey(mem_a))
            {
                map[mem_a] = map[mem_a] + 1;
            }
            else
            {
                map.Add(mem_a, 1);
            }
        }
        foreach (string mem_b in arrB)
        {
            if (map.ContainsKey(mem_b))
            {
                map[mem_b] = map[mem_b] + 1;
            }
            else
            {
                map.Add(mem_b, 1);
            }
        }
        return map.Where(x => x.Value == 1).Select(x => x.Key).ToArray();
    }

}

