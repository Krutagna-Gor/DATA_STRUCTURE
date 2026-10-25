
#include <iostream>
#include <queue>
using namespace std;

int graph[20][20], visited[20];
int n;

// Depth First Search
void DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// Breadth First Search
void BFS(int start)
{
    queue<int> q;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "DFS Traversal: ";
    DFS(start);

    cout << endl;
    cout << "BFS Traversal: ";
    BFS(start);

    cout << endl;
    return 0;
}
