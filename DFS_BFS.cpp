#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void dfs (vector<vector<int>>& graph, int start) {
    int size = graph.size();
    vector<bool> visited(size, false);
    stack<int> stk;
    stk.push(start);

    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
            for (int neighbour : graph[node]) {
                if (!visited[neighbour])
                    stk.push(neighbour);
            }
        }
    }
}

void bfs (vector<vector<int>>& graph, int start) {
    int size = graph.size();
    vector<bool> visited(size, false);
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
            for (int neighbour : graph[node]) {
                if (!visited[neighbour])
                    q.push(neighbour);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1, 5}, {2, 4}};
    int startNode = 0;
    
    cout << "DFS traversal starting from node " << startNode << " : ";
    dfs(graph, startNode);

    cout << endl;

    cout << "BFS traversal starting from node " << startNode << " : ";
    bfs(graph, startNode);

    cout << endl;
    
    return 0;
}
