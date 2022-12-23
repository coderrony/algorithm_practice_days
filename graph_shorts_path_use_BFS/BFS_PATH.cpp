#include <bits/stdc++.h>
using namespace std;

// shorted path in graph use bsf algorithm

class Graph
{

private:
    vector<int> dist;
    vector<int> pred;

public:
    int node;
    // list<int> *adj;
    vector<int> *adj;

    Graph(int v)
    {
        this->node = v;
        // this->adj = new list<int>[v];
        this->adj = new vector<int>[v];
        this->dist = vector<int>(v, 0);
        this->pred = vector<int>(v, -1);
    }

    void addAdj(int v, int e)
    {

        this->adj[v].push_back(e);
        this->adj[e].push_back(v);
    }

    bool BFS(int source, int des)
    {
        vector<bool> visit(this->node, false);
        queue<int> q;
        q.push(source);
        visit[source] = true;

        while (!q.empty())
        {
            int value = q.front();
            q.pop();
            for (auto ele : adj[value])
            {
                if (visit[ele] == false)
                {
                    visit[ele] = true;
                    dist[ele] = dist[value] + 1; // according to parent node like if parent laval is 1 then child lave have 1+1 = 2
                    pred[ele] = value;           // pred array store parent node
                    q.push(ele);

                    if (ele == des)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void BFS_shorts_path(int source, int des)
    {
        if (BFS(source, des) == false)
        {
            cout << "source node and destination note are not connect";
            return;
        }

        stack<int> path;
        path.push(des);
        int traverse = des;
        while (pred[traverse] != -1)
        {
            path.push(pred[traverse]);
            traverse = pred[traverse];
        }

        cout << "Source " << source << " destination " << des << " Shorts path: ";
        while (!path.empty())
        {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl
             << "Laval of node " << des << " is " << dist[des];
    }

    void DFS(int source)
    {

        static vector<bool> visit(node, false);

        cout << source << " ";
        visit[source] = true;
        for (int i = 0; i < adj[source].size(); i++)
        {
            if (visit[adj[source][i]] == false)
            {
                DFS(adj[source][i]);
            }
        }
    }
};

int main()
{
    int n, e, x, y;
    cin >> n >> e;
    Graph g(n);

    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        g.addAdj(x, y);
    }

    g.BFS_shorts_path(1, 4);

    return 0;
}

/*

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