#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src;
    int des;
    int weight;
};

bool compareWeight(Edge first, Edge second)
{
    return (first.weight < second.weight);
}

int Parent(int v, int *parent)
{
    int currParent = parent[v];
    int currChild = v;
    while (currChild != currParent)
    {
        currChild = currParent;
        currParent = parent[currChild];
    }
    return currParent;
}

bool unionFind(int v1, int v2, int *parent)
{
    int vp1 = Parent(v1, parent);
    int vp2 = Parent(v2, parent);

    if (vp1 != vp2)
    {
        parent[vp1] = vp2;
        return true;
    }
    else
        return false;
}

int main()
{
    int v, e;
    cin >> v >> e;
    Edge *input = new Edge[e];
    Edge *MST = new Edge[v - 1];

    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].src = s;
        input[i].des = d;
        input[i].weight = w;
    }

    sort(input, input + e, compareWeight);

    int count = 0;
    int *parent = new int[v];

    for (int i = 0; i < v; i++)
        parent[i] = i;

    int i = 0;
    while (count != (v - 1))
    {
        Edge curr = input[i];
        i++;
        if (unionFind(curr.src, curr.des, parent))
        {
            MST[count] = curr;
            count++;
        }
        else
            continue;
    }

    for (int i = 0; i < v - 1; i++)
    {
        int s, d, w;
        s = MST[i].src;
        d = MST[i].des;
        w = MST[i].weight;

        cout << min(s, d) << " " << max(s, d) << " " << w << endl;
    }

    delete[] parent;
    delete[] input;
    delete[] MST;
}
