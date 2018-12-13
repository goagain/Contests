#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

struct SegmentTreeNode
{
    long long waitAdd;
    long long value;
    int sign;
    int l, r;
    bool changed;
};
SegmentTreeNode nodes[MAXN * 2];

inline int getLChild(int n)
{
    return n * 2;
}
inline int getRChild(int n)
{
    return n * 2 + 1;
}
inline int getParent(int n)
{
    return n / 2;
}

void update(int n, int l, int r, int add);
long long query(int n, int l, int r);
void transform(int n, int l, int r);

void Construct(int n, int l, int r)
{
    SegmentTreeNode &root = nodes[n];
    root.l = l;
    root.r = r;
    root.sign = 1;
    root.value = 0;
    root.waitAdd = 0;
    root.changed = false;
    if (l != r)
    {
        int mid = (l + r) / 2;
        Construct(getLChild(n), l, mid);
        Construct(getRChild(n), mid + 1, r);
    }
}

void transform(int n, int l, int r)
{
    SegmentTreeNode &node = nodes[n];
    if (l > node.r || r < node.l)
    {
        return;
    }
    // printf("transform n = %d, l = %d, r = %d\n", n, l, r);

    if (node.l == node.r)
    {
        node.value = -node.value;
        return;
    }
    if (l <= node.l && r >= node.r)
    {
        node.sign *= -1;
    }
    else
    {
        node.changed = true;
        if (node.waitAdd != 0)
        {
            update(getLChild(n), node.l, node.r, node.waitAdd);
            update(getRChild(n), node.l, node.r, node.waitAdd);
            node.waitAdd = 0;
        }
        transform(getLChild(n), l, r);
        transform(getRChild(n), l, r);
    }
}

void update(int n, int l, int r, int add)
{
    SegmentTreeNode &node = nodes[n];
    if (l > node.r || r < node.l)
    {
        return;
    }
    // printf("update n = %d, l = %d, r = %d\n", n, l, r);

    if (node.l == node.r)
    {
        node.value += add;
        return;
    }
    if (l <= node.l && r >= node.r)
    {
        node.waitAdd += add * node.sign;
    }
    else
    {
        update(getLChild(n), l, r, add * node.sign);
        update(getRChild(n), l, r, add * node.sign);
        int tl = max(l, node.l);
        int tr = min(r, node.r);
        node.value += (tr - tl + 1) * add * node.sign;
    }
}

long long query(int n, int l, int r)
{
    SegmentTreeNode &node = nodes[n];
    // printf("query n = %d, l = %d, r = %d\n", n, l, r);
    if (l > node.r || r < node.l)
    {
        return 0;
    }
    if (node.l == node.r)
    {
        return node.value;
    }
    if (l <= node.l && r >= node.r) 
    {
        if (node.changed)
        {
            node.value = query(getLChild(n), l, r) + query(getRChild(n), l, r);
            node.changed = false;
        }
        return node.sign * (node.value + node.waitAdd * (node.r - node.l + 1));
    }
    else
    {
        int tl = max(l, node.l);
        int tr = min(r, node.r);

        return node.sign * (node.waitAdd * (tr - tl + 1) + query(getLChild(n), l, r) + query(getRChild(n), l, r));
    }
}

int main(int argc, char const *argv[])
{

    // freopen("input2.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    int l, r, add, t;
    while (cin >> n)
    {
        Construct(1, 1, n);
        for (int i = 1; i <= n; i++)
        {
            cin >> t;
            update(1, i, i, t);
        }
        int handleCount = 0;
        scanf("%d", &handleCount);
        while(handleCount--)
        {
            string handle;
            cin >> handle;
            if (handle == "Q")
            {
                cin >> l >> r;
                cout << query(1, l, r) << endl;
            }
            else if(handle == "A")
            {
                cin >> l >> r >> add;
                update(1, l, r, add);
            }
            else if(handle == "T")
            {
                cin >> l >> r;
                transform(1, l, r);
            }

            // for (int i = 1; i <= n; i++)
            // {
            //     printf("%d ", query(1, i, i));
            // }
            // printf("\n");
            // fflush(stdout);

        }
    }
}