#include <bits/stdc++.h>
using namespace std;

int adjMatrix[100][100];
int counting[100] = {0};
void BFS(int source, int n)
{

    queue<int> q;
    int visit[100] = {0};

    q.push(source);

    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        visit[node] = 1;

        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[node][i] == 1 && visit[i] != 1)
            {
                visit[i] = 1;
                q.push(i);
            }
            if (adjMatrix[node][i] == 1)
            {
                counting[i] += 1;
            }
        }
    }
}

bool chk_connect(int n1, int n2, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (adjMatrix[n1][i] == 1 && n2 == i)
        {
            return true;
        }
    }
    return false;
}

void DFS(int source, int sz)
{
    static int visit[100] = {0};
    visit[source] = 1;
    cout << source << " ";
    for (int i = 0; i < sz; i++)
    {
        if (adjMatrix[source][i] == 1 && !visit[i])
        {
            DFS(i, sz);
        }
        if (adjMatrix[source][i] == 1)
        {
            counting[i] += 1;
        }
    }
}

int main()
{
    int v, e, x, y;
    cin >> v >> e;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }

    // BFS(0, v);
    DFS(0, v);
    cout << endl;
    bool chk = chk_connect(5, 3, v);
    cout << chk;

    // for (int i = 0; i < v; i++)
    // {
    //     cout << i << " -> " << counting[i] << endl;
    // }

    return 0;
}

/*
Bi direction weight graph

7 10
0 1
0 2
0 5
1 3
2 3
2 5
3 6
6 5
6 4
5 4


*/
