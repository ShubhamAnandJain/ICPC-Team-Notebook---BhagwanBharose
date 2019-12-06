int n; // number of vertices
vector<int> adj[LIM], ans; // adjacency list of graph
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);}
    ans.push_back(v);}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);}
    reverse(ans.begin(), ans.end());}