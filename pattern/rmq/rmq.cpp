#include <bits/stdc++.h>
using namespace std;
template <typename T, typename Compare = std::less<T>>
class RMQ
{
  public:
    vector<vector<int>> st;
    function<bool (T, T)> cmp;

    RMQ(vector<T> array)
    {
        cmp = Compare();
        size_t size = array.size();
        int k = log2(size);
        st.push_back(array);
        for (int k = 1; (1 << k) < size; k++)
        {
            vector<T> tmp = vector<T>(size);
            for (size_t i = 0; i < tmp.size(); i++)
            {
                int rIndex = min(i + (1 << (k - 1)), size);
                tmp[i] = cmp(st[k - 1][i], st[k - 1][rIndex]) ? st[k - 1][i] : st[k - 1][rIndex];
            }
            st.push_back(move(tmp));
        }
    }

    T query(size_t l, size_t r)
    {
        int k = log2(r - l);
        if (cmp(st[k][l], st[k][r - (1 << k)]))
            return st[k][l];
        else
            return st[k][r - (1 << k)];
    }
};