#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
using namespace std;

class Graph {
public:
    int num_vertices;
    int num_edges;
    vector<vector<int>> g;

    Graph(int n) : num_vertices(n), num_edges(0), g(n + 1) {
    };

    void AddUndirected(int x, int y) {
        g[x].push_back(y);
        g[y].push_back(x);
        num_edges++;
    }

    void AddDirected(int x, int y, int w) {
        g[x].push_back(y);
        num_edges++;
    }

    void BFS(int source) {
        vector<int> visited(num_vertices + 1, -1);
        visited[source] = 0;
        int u, v;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (int i = 0; i < g[u].size(); ++i) {
                v = g[u][i];
                if (visited[v]==-1) {
                    visited[v] = visited[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i < visited.size(); ++i)printf("%d ", visited[i]);
        printf  ("\n");
    }

    void DFS(int source) {
        vector<int> visited(num_vertices + 1, -1);
        int u, v;
        stack<int> s;
        s.push(source);
        while (!s.empty()) {
            u = s.top();
            s.pop();
            visited[u]=1;
            for (int i = 0; i < g[u].size(); ++i) {
                v = g[u][i];
                if (visited[v]==-1) {
                    s.push(v);
                }
            }
            
        }
        
        for(int i=1;i<visited.size();++i)printf("%d ",visited[i]);
        printf("\n");
    }

    void Print() {
        for (int i = 1; i <= num_vertices; ++i) {
            printf("%d: ", i);
            for (int j = 0; j < g[i].size(); ++j) {
                printf("%d ", g[i][j]);
            }
            printf("\n");
        }
    }

};

class WeightedGraph {
public:
    int num_vertices;
    int num_edges;
    vector<vector<pair<int, int> > > g;
    
    WeightedGraph(int n) : num_vertices(n), num_edges(0), g(n + 1) {};
    
    void AddUndirected(int x,int y,int w) {
        g[x].push_back(make_pair(y,w));
        g[y].push_back(make_pair(x,w));
        num_edges++;
    }

    void AddDirected(int x, int y, int w) {
        g[x].push_back(make_pair(y, w));
        num_edges++;
    }

    void BFS(int source) {
        vector<int> visited(num_vertices + 1, -1);
        visited[source] = 0;
        int u, v;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (int i = 0; i < g[u].size(); ++i) {
                v = g[u][i].first;
                if (visited[v] == -1) {
                    visited[v] = visited[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i < visited.size(); ++i)printf("%d ", visited[i]);
        printf("\n");
    }

    void DFS(int source) {
        vector<int> visited(num_vertices + 1, -1);
        visited[source] = 0;
        int u, v;
        stack<int> s;
        s.push(source);
        while (!s.empty()) {
            u = s.top();
            s.pop();
            visited[u]=1;
            for (int i = 0; i < g[u].size(); ++i) {
                v = g[u][i].first;
                if (visited[v]==-1) {
                    s.push(v);
                }
            }
            
        }

        for (int i = 1; i < visited.size(); ++i)printf("%d ", visited[i]);
        printf("\n");
    }
    
    void Print() {
        for (int i = 1; i <= num_vertices; ++i) {
            printf("%d: ", i);
            for (int j = 0; j < g[i].size(); ++j) {
                printf("%d(%d) ", g[i][j].first,g[i][j].second);
            }
            printf("\n");
        }
    }
};

int main() {
    
}
