#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

enum INFLUENCE {
	NONE = -1,
	ONE,
	ZERO,
	NOT,
	EQUAL,
};

struct Node
{
	string op;
	int o1 = 0, o2 = 0;
	
	int parent = 0;
	int val = -1;
	INFLUENCE influence = NONE;
};
Node tree[1001000];

int walk(int n)
{
	Node& node = tree[n];
	int result = 0;
	if (node.op == "AND" || node.op == "OR" || node.op == "XOR")
	{
		int o1 = walk(node.o1);
		int o2 = walk(node.o2);
		if (node.op == "AND")
			return node.val = o1 & o2;
		if (node.op == "OR")
			return node.val = o1 | o2;
		if (node.op == "XOR")
			return node.val = o1 ^ o2;
	}
	else
	{
		if (node.op == "IN")
			return node.val = node.o1;
		int o1 = walk(node.o1);
		if (node.op == "NOT")
			return node.val = !o1;
	}
	return 0;
}

INFLUENCE one(INFLUENCE influence)
{
	if (influence == ONE || influence == ZERO)
		return influence;
	if (influence == NOT)
		return ZERO;
	if (influence == EQUAL)
		return ONE;
}

INFLUENCE zero(INFLUENCE influence)
{
	if (influence == ONE || influence == ZERO)
		return influence;
	if (influence == NOT)
		return ONE;
	if (influence == EQUAL)
		return ZERO;
}

INFLUENCE not_(INFLUENCE influence)
{
	if (influence == ONE || influence == ZERO)
		return influence;
	if (influence == NOT)
		return EQUAL;
	if (influence == EQUAL)
		return NOT;
}

INFLUENCE equal(INFLUENCE influence)
{
	return influence;
}

void process(int index)
{
	if (index == 0)
		return;
	Node& node = tree[index];
	if (index == 1)
		node.influence = EQUAL;
	if (node.op == "IN")
		return;
	Node &l = tree[node.o1], &r = tree[node.o2];
	if (node.op == "AND")
	{
		if (l.val)
			r.influence = equal(node.influence);
		else
			r.influence = zero(node.influence);
		if (r.val)
			l.influence = equal(node.influence);
		else
			l.influence = zero(node.influence);
	}
	if (node.op == "OR")
	{
		if (l.val)
			r.influence = one(node.influence);
		else
			r.influence = equal(node.influence);
		if (r.val)
			l.influence = one(node.influence);
		else
			l.influence = equal(node.influence);
	}
	if (node.op == "XOR")
	{
		if (l.val)
			r.influence = not_(node.influence);
		else
			r.influence = equal(node.influence);
		if (r.val)
			l.influence = not_(node.influence);
		else
			l.influence = equal(node.influence);
	}
	if (node.op == "NOT")
	{
		l.influence = not_(node.influence);
	}
	process(node.o1);
	process(node.o2);
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			string op;
			int o1 = 0, o2 = 0;
			cin >> op;
			if (op == "AND" || op == "OR" || op == "XOR")
				cin >> o1 >> o2;
			else
				cin >> o1;
			tree[i].op = op;
			tree[i].o1 = o1;
			tree[i].o2 = o2;
			tree[o1].parent = i;
			tree[o2].parent = i;
		}
		walk(1);
		process(1);
		for (int i = 1; i <= n; i++)
		{
			//cout << endl << i << " " << tree[i].influence << " val = " << tree[i].val << " :";
			if (tree[i].op == "IN")
			{
				switch (tree[i].influence)
				{
				case ZERO:
					cout << 0;
					break;
				case ONE:
					cout << 1;
					break;
				case NOT:
					cout << tree[i].val;
					break;
				case EQUAL:
					cout << !tree[i].val;
					break;
				default:
					break;
				}
			}
		}
	}
	return 0;
}