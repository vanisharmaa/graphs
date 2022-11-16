/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/

bool BFS(vector<vector<int>>& graph, int n, vector<int>& vis, vector<int>& vec, int sv){
    queue<pair<int, int>> q;
    q.push({sv, 0});
    vis[sv] = true;
    vec[sv] = 0;
    while(!q.empty()){
        int node = q.front().first;
        int color = q.front().second;
        q.pop();
        for(int i = 0; i < graph[node].size(); i++){
            if(!vis[graph[node][i]]){
                q.push({graph[node][i], !color});
                vis[graph[node][i]] = 1;
                vec[graph[node][i]] = !vec[node];
            }
            else if(vec[graph[node][i]] == color){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> vec(n, -1);
    for(int i = 0; i < n; i++){
        if (!vis[i]){
            bool b = BFS(graph, n, vis, vec, i);
            if (!b){
                return false;
            }
        }
    }
    return true;
}
