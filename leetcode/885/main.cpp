#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int ans = 0;
        sort(people.begin(), people.end());
        int head = 0, tail = people.size() - 1;
        while (tail >= head)
        {
            if (head == tail)
            {
                ans++;
                break;
            }
            else if (people[head] + people[tail] <= limit)
            {
                ans++;
                head++;
                tail--;
            }
            else
            {
                ans++;
                tail--;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}
