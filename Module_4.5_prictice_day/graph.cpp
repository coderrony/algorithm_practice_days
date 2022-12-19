#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int node;
    vector<int> *adj_list;
    Graph(int v)
    {
        this->node = v;
        this->adj_list = new vector<int>[v];
    }

    void addAdj(int v, int e)
    {
        adj_list[v].push_back(e);
        adj_list[e].push_back(v);
    }
    void printNode(int source)
    {
        for (auto ele : adj_list[source])
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    void BFS(int source)
    {
        vector<bool> visit(node, false);
        queue<int> q;
        q.push(source);
        visit[source] = true;
        while (!q.empty())
        {
            int x = q.front();
            cout << x << " ";
            q.pop();

            for (auto ele : adj_list[x])
            {
                if (visit[ele] != true)
                {
                    q.push(ele);
                    visit[ele] = true;
                }
            }
        }
    }

    void DFS(int source)
    {
        static vector<bool> visit(node, false);
        visit[source] = true;
        cout << source << " ";
        for (auto ele : adj_list[source])
        {
            if (visit[ele] != true)
            {
                DFS(ele);
            }
        }
    }
};

int main()
{

    Graph g(5);

    g.addAdj(0, 3);
    g.addAdj(0, 2);
    g.addAdj(1, 3);
    g.addAdj(1, 4);
    g.addAdj(2, 4);
    g.addAdj(2, 3);
    g.addAdj(2, 1);

    // for (int i = 0; i < 5; i++)
    // {
    //     g.printNode(i);
    // }
    g.BFS(1);
    cout << endl;
    g.DFS(1);

    return 0;
}