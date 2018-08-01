using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
public class Solution
{
    HashSet<KeyValuePair<int, int>> visited = new HashSet<KeyValuePair<int, int>>();
    struct Pattern
    {
        public char c;
        public bool isRepeat;
        public Pattern(char c, bool isRepeat)
        {
            this.c = c;
            this.isRepeat = isRepeat;
        }
    }
    bool TryMatch(string s, int indexS, List<Pattern> p, int indexP)
    {
        if (visited.Contains(new KeyValuePair<int, int>(indexS, indexP)))
            return false;
        visited.Add(new KeyValuePair<int, int>(indexS, indexP));
        if (indexS == s.Length && indexP == p.Count)
            return true;
        if (indexP == p.Count)
            return false;
        Pattern current = p[indexP];
        if (current.isRepeat)
        {
            if (indexS < s.Length)
            {
                if (isCharMatch(s[indexS], current.c))
                {
                    if (TryMatch(s, indexS + 1, p, indexP))
                        return true;
                }
                if (TryMatch(s, indexS, p, indexP + 1))
                    return true;
            }
            else
            {
                return TryMatch(s, indexS, p, indexP + 1);
            }
        }
        if (indexS < s.Length)
        {
            if (isCharMatch(s[indexS], current.c))
            {
                if (TryMatch(s, indexS + 1, p, indexP + 1))
                    return true;
            }
        }
        return false;
    }
    bool isCharMatch(char a, char b)
    {
        if (b == '.')
            return true;
        return a == b;
    }

    public bool IsMatch(string s, string p)
    {
        visited = new HashSet<KeyValuePair<int, int>>();
        List<Pattern> list = new List<Pattern>();
        for (int i = 0; i < p.Length; i++)
        {
            if (i < p.Length - 1 && p[i + 1] == '*')
            {
                list.Add(new Pattern(p[i], true));
                i++;
            }
            else
            {
                list.Add(new Pattern(p[i], false));
            }
        }
        return TryMatch(s, 0, list, 0);
    }

    public static void Main(string[] args)
    {
        Solution solution = new Solution();
        Console.Out.WriteLine(solution.IsMatch("ab", ".*c"));

        Console.Out.WriteLine(solution.IsMatch("aa", "a*"));
        Console.Out.WriteLine(solution.IsMatch("mississippi", "mis*is*p*."));

        Console.Out.WriteLine(solution.IsMatch("a", "ab*"));

    }
}